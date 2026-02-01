#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto sa = a;
    std::sort(sa.begin(), sa.end());
    int k = sa[(n - 1) / 2];

    auto count = [&](int x) {
        std::vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (a[i] >= x ? 1 : -1);
        }

        i64 res = 0;
        int offset = n;
        Fenwick<int> fen(2 * n + 1);
        for (int r = 0; r <= n; r++) {
            int v = pre[r] + offset;
            res += fen.sum(v);
            fen.add(v, 1);
        }
        return res;
    };

    i64 ans = count(k) - count(k + 1);
    std::cout << ans << "\n";

    return 0;
}