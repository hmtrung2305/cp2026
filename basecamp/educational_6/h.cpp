#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j];
            for (int k = i + 1; k <= j; k++) {
                if (s[i] == s[k]) {
                    int l = i + 1 <= k - 1 ? dp[i + 1][k - 1] : 0;
                    int r = k + 1 <= j ? dp[k + 1][j] : 0;
                    dp[i][j] = std::max(dp[i][j], l + r + 2);
                }
            }
        }
    }

    int ans = n - dp[0][n - 1];
    std::cout << ans << "\n";

    return 0;
}