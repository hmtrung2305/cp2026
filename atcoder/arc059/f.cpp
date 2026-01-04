#include <bits/stdc++.h>

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= N; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % P;
        }
        for (int j = 0; j < N; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j + 1] * 2 % P) % P;
        }
    }

    std::cout << dp[N][s.size()] << "\n";

    return 0;
}