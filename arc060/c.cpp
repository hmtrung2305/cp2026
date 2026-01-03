#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, A;
    std::cin >> N >> A;

    std::vector<int> x(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<i64>> dp(N + 1, std::vector<i64>(N * A + 1));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = N; j > 0; j--) {
            for (int k = N * A; k >= x[i]; k--) {
                dp[j][k] += dp[j - 1][k - x[i]];
            }
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[i][i * A];
    }
    std::cout << ans << "\n";

    return 0;
}