#include <bits/stdc++.h>

void solve() {
    std::string S;
    std::cin >> S;

    int n = S.size();

    std::vector<std::array<int, 5>> dp(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i + 1][j] = dp[i][j];
        }
        if (S[i] == 'I') {
            dp[i + 1][1] = dp[i][0] + 1;
        } else if (S[i] == 'C') {
            dp[i + 1][2] = dp[i][1];
            dp[i + 1][4] = dp[i][3];
        } else {
            dp[i + 1][3] = dp[i][2];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            std::cerr << dp[i][j] << " \n"[j == 4];
        }

    }

    std::cout << dp[n][4] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}