#include <bits/stdc++.h>

using i64 = long long;

struct FenwickTree {
    int n;
    std::vector<int> a;

    FenwickTree(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, 0);
    }

    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    int kth(int k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i >>= 1) {
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

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> cnt(m);
    std::vector<std::vector<int>> s(n + 1);
    std::vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        s[++cnt[x]].push_back(x);
        pre[cnt[x]]++;
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + m - pre[i];
    }

    std::vector<i64> k(q);
    for (int i = 0; i < q; i++) {
        std::cin >> k[i];
    }

    std::vector<int> p(q);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](int i, int j) {
            return k[i] < k[j];
        });

    FenwickTree fen(m);

    for (int i = 0; i < m; i++) {
        if (!cnt[i]) {
            fen.add(i, 1);
        }
    }

    std::vector<int> ans(q);

    int j = 1;
    for (auto i : p) {
        i64 x = k[i] - n;
        for (; j <= n && x > pre[j]; j++) {
            for (auto y : s[j]) {
                fen.add(y, 1);
            }
            if (j < n) {
                for (auto y : s[j + 1]) {
                    fen.add(y, -1);
                }
            }
        }
        x = (x - 1 - pre[j - 1] + m) % m;
        ans[i] = fen.kth(x);
    }

    for (int i = 0; i < q; i++) {
        std::cout << ans[i] + 1 << "\n";
    }

    return 0;
}