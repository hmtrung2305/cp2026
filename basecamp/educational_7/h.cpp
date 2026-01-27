#include <bits/stdc++.h>

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l;

    while (std::cin >> l && l) {
        int n;
        std::cin >> n;

        std::vector<int> a(n + 2);
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        a[n + 1] = l;
        n += 2;

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, inf));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
            if (i < n - 1) {
                dp[i][i + 1] = 0;
            }
        }
        for (int len = 2; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                for (int j = i + 1; j < i + len; j++) {
                    dp[i][i + len] = std::min(dp[i][i + len], dp[i][j] + dp[j][i + len] + (a[i + len] - a[i]));
                }
            }
        }
        std::cout << "The minimum cutting is " << dp[0][n - 1] << ".\n";
    }

    return 0;
}