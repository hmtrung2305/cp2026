#include <bits/stdc++.h>

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, C;
    std::cin >> N >> C;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int mx = *std::max_element(B.begin(), B.end());
    std::vector<std::vector<int>> pw(mx + 1, std::vector<int>(C + 1));
    for (int i = 1; i <= mx; i++) {
        pw[i][0] = 1;
        for (int j = 1; j <= C; j++) {
            pw[i][j] = 1LL * pw[i][j - 1] * i % P;
        }
    }

    std::vector<std::vector<int>> s(N, std::vector<int>(C + 1));
    for (int i = 0; i < N; i++) {
        s[i][0] = B[i] - A[i] + 1;
        for (int j = 1; j <= C; j++) {
            for (int x = A[i]; x <= B[i]; x++) {
                s[i][j] = (s[i][j] + pw[x][j]) % P;
            }
        }
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(C + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= C; j++) { 
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - k] * s[i - 1][k] % P) % P;
            }
        }
    }
    std::cout << dp[N][C] << "\n";

    return 0;
}