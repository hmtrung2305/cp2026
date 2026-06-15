#include <bits/stdc++.h>

using i64 = long long;

struct Fenwick {
    int n;
    std::vector<i64> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, 0LL);
    }
    
    void add(int x, i64 v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    i64 sum(int x) {
        i64 ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    i64 rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(i64 k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> num;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] > 0) {
            num.push_back(a[i]);
        }
    }

    std::vector<int> x(q), v(q);
    for (int i = 0; i < q; i++) {
        std::cin >> x[i] >> v[i];
        x[i]--;
        if (v[i] > 0) {
            num.push_back(v[i]);
        }
    }

    if (num.size() == 0) {
        for (int i = 0; i < q; i++) {
            std::cout << 1 << "\n";
        }
        return 0;
    }

    std::sort(num.begin(), num.end());
    num.erase(std::unique(num.begin(), num.end()), num.end());
    auto val = [&](int x) {
        return std::lower_bound(num.begin(), num.end(), x) - num.begin();
    };

    Fenwick sum(num.size()), cnt(num.size());
    i64 neg = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            sum.add(val(a[i]), a[i]);
            cnt.add(val(a[i]), 1);
        } else {
            neg -= a[i];
        }
    }

    for (int i = 0; i < q; i++) {
        if (a[x[i]] > 0) {
            sum.add(val(a[x[i]]), -a[x[i]]);
            cnt.add(val(a[x[i]]), -1);
        } else if (a[x[i]] < 0) {
            neg += a[x[i]];
        }
        a[x[i]] = v[i];
        if (a[x[i]] > 0) {
            sum.add(val(a[x[i]]), a[x[i]]);
            cnt.add(val(a[x[i]]), 1);
        } else {
            neg -= a[x[i]];
        }

        int p = sum.kth(neg);

        int ans = cnt.sum(p) + 1;
        i64 rem = neg - sum.sum(p);
        if (rem >= num[p] && p != num.size()) {
            assert(num[p] != 0);
            ans += rem / num[p];
        }

        std::cout << ans << "\n";
    }

    return 0;
}