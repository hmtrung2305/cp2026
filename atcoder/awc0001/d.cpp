#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<std::vector<i64>> dp(N, std::vector<i64>(M + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M - B[i]; j++) {
            for (int k = std::max(i - K, 0); k < i; k++) {
                dp[i][j + B[i]] = std::max(dp[i][j + B[i]], dp[k][j] + A[i]);
            }
            dp[i][j + B[i]] = std::max(dp[i][j + B[i]], 1LL * A[i]);
        }
    }

    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        ans = std::max(ans, dp[i][M]);
    }
    std::cout << ans << "\n";

    return 0;
}