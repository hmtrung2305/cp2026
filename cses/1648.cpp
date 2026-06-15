#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    const int B = std::max(1, (int)std::sqrt(n));
    int nb = (n + B - 1) / B;

    std::vector<i64> block(nb);
    for (int i = 0; i < n; i++) {
        block[i / B] += x[i];
    }

    for (int i = 0; i < q; i++) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int k, u;
            std::cin >> k >> u;
            k--;
            block[k / B] -= x[k];
            x[k] = u;
            block[k / B] += x[k];
        } else {
            int l, r;
            std::cin >> l >> r;
            l--;
            r--;

            i64 ans = 0;
            int bl = l / B;
            int br = r / B;

            if (bl == br) {
                for (int j = l; j <= r; j++) {
                    ans += x[j];
                }
                std::cout << ans << "\n";
                continue;
            }

            for (int j = l; j <= std::min(r, (bl + 1) * B - 1); j++) {
                ans += x[j];
            }
            for (int j = bl + 1; j < br; j++) {
                ans += block[j];
            }
            for (int j = std::max(l, br * B); j <= r; j++) {
                ans += x[j];
            }

            std::cout << ans << "\n";
        }
    }

    return 0;
}