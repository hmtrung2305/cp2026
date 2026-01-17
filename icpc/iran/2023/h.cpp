#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int ans = 0;
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'W') {
                dp[i][j] = 0;
            } else if (i < n - 1) {
                if (dp[i + 1][j] != -1) {
                    dp[i][j] = std::max(dp[i][j], dp[i + 1][j] + (s[i][j] == 'B'));
                }
                if (j && dp[i + 1][j - 1] != -1) {
                    dp[i][j] = std::max(dp[i][j], dp[i + 1][j - 1] + (s[i][j] == 'B'));
                }
                if (j < m - 1 && dp[i + 1][j + 1] != -1) {
                    dp[i][j] = std::max(dp[i][j], dp[i + 1][j + 1] + (s[i][j] == 'B'));
                }
            }
            ans = std::max(ans, dp[i][j]);
        }
    }

    std::cout << ans << "\n";

    return 0;
}