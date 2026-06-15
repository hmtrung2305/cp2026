#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int q;
    std::cin >> q;

    std::vector<std::array<int, 3>> qry(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        r--;
        qry[i] = {l, r, i};
    }

    const int B = std::sqrt(n);
    std::sort(qry.begin(), qry.end(),
        [&](std::array<int, 3> x, std::array<int, 3> y) {
            int bx = x[0] / B;
            int by = y[0] / B;
            if (bx == by) {
                return x[1] < y[1];
            }
            return x[0] < y[0];
        });

    int cnt = 0;
    std::vector<int> f(1E6 + 1);
    auto add = [&](int i) {
        if (i < 0 || i >= n) {
            return;
        }
        f[a[i]]++;
        cnt += f[a[i]] == 1;
    };
    auto del = [&](int i) {
        if (i < 0 || i >= n) {
            return;
        }
        f[a[i]]--;
        cnt -= f[a[i]] == 0;
    };

    std::vector<int> ans(q);
    int L = -1, R = -1;
    for (auto [l, r, i] : qry) {
        while (L < l) {
            del(L++);
        }
        while (L > l) {
            add(--L);
        }
        while (R < r) {
            add(++R);
        }
        while (R > r) {
            del(R--);
        }
        ans[i] = cnt;
    }

    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}