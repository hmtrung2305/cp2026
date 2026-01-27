#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    std::vector<std::vector<i64>> binom(n + 1);
    binom[0].push_back(1);
    for (int i = 1; i <= n; i++) {
        binom[i].resize(std::min(x + 1, i + 1));
        binom[i][0] = 1;
        for (int j = 1; j < std::min(i, x + 1); j++) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
        if (x >= i) {
            binom[i][i] = 1;
        }
    }

    real ans = 0;
    for (int i = 1; i <= n - x + 1; i++) {
        ans += (1LL << i) * binom[n - i][x - 1];
    }

    ans /= binom[n][x];
    std::cout << std::fixed << std::setprecision(4) << ans << "\n";

    return 0;
}