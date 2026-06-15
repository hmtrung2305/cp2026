#include <bits/stdc++.h>

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    const int B = std::sqrt(N);

    std::vector<int> dp(N, 1);
    std::vector<std::vector<int>> s(B + 1, std::vector<int>(B + 1));
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] > B) {
            for (int j = i + A[i]; j < N; j += A[i]) {
                dp[i] = (dp[i] + dp[j]) % P;
            }
        } else {
            dp[i] = (dp[i] + s[A[i]][i % A[i]]) % P;
        }
        for (int j = 1; j <= B; j++) {
            s[j][i % j] = (s[j][i % j] + dp[i]) % P;
        }
    }
    std::cout << dp[0] << "\n";

    return 0;
}