#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    std::vector<std::vector<int>> dp(1 << 3, std::vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << 3); mask++) {
            for (int x = 0; x < 3; x++) {
                if (mask >> x & 1) {
                    if (t[i] != x) {
                        continue;
                    }
                    dp[mask][x] += 1;
                    for (int y = 0; y < 3; y++) {
                        if (mask >> y & 1) {
                            continue;
                        }
                        dp[mask][x] = std::max(dp[mask][x], dp[mask ^ (1 << y)][y] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << 3); mask++) {
        for (int i = 0; i < 3; i++) {
            ans = std::max(ans, dp[mask][i]);
        }
    }
    std::cout << ans << "\n";

    return 0;
}