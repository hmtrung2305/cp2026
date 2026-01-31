#include <bits/stdc++.h>

using i64 = int;

struct Fenwick {
    int n;
    std::vector<i64> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, 0);
    }

    void add(int x, i64 v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    i64 sum(int x) {
        i64 res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            res += a[i - 1];
        }
        return res;
    }

    i64 rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mx = *std::max_element(a.begin(), a.end());
    int B = 320;

    std::vector<i64> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    std::vector<std::vector<std::array<i64, 3>>> on(n + 2);
    std::vector<std::vector<std::array<i64, 3>>> off(n + 2);

    for (int i = B + 1; i <= n; i++) {
        int m = B + 1;
        while (m <= i) {
            int t = a[i - 1] / m;
            if (t == 0) {
                break;
            }

            int L = m;
            int R = std::min(i, a[i - 1] / t);
            int minL = i - R + 1;
            int maxL = i - L + 1;
            if (minL <= maxL) {
                on[minL].push_back({i, t * (i + 1), -t});
                if (minL + 1 <= n + 1) {
                    off[maxL + 1].push_back({i, 0, 0});
                }
            }
            m = R + 1;
        }
    }

    std::vector<std::vector<std::array<int, 2>>> qry(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        qry[l].push_back({r, i});
    }

    std::vector<i64> ans(q);
    Fenwick fena(n + 1), fenb(n + 1);
    std::vector<i64> cura(n + 1), curb(n + 1);

    for (int l = 1; l <= n; l++) {
        for (auto [i, na, nb] : off[l]) {
            fena.add(i, na - cura[i]);
            fenb.add(i, nb - curb[i]);
            cura[i] = na;
            curb[i] = nb;
        }

        for (auto [i, na, nb] : on[l]) {
            fena.add(i, na - cura[i]);
            fenb.add(i, nb - curb[i]);
            cura[i] = na;
            curb[i] = nb;
        }

        for (auto [r, i] : qry[l]) {
            int x = std::min(B, r - l + 1);

            for (int j = 1; j <= x; j++) {
                ans[i] += a[l - 1 + j - 1] % j;
            }

            if (l + x <= r + 1) {
                ans[i] += pre[r] - pre[l + x - 1];
            }

            if (l + B <= r) {
                i64 suma = fena.rangeSum(l + B, r + 1);
                i64 sumb = fenb.rangeSum(l + B, r + 1);
                ans[i] -= suma + l * sumb;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
