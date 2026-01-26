#include <bits/stdc++.h>

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N, std::vector<int>(N));
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    std::vector<int> cnt(1 << N);
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((mask >> i & 1) && (mask >> j & 1)) {
                    if (adj[i][j]) {
                        cnt[mask]++;
                    } else {
                        cnt[mask]--;
                    }
                }
            }
        }
    }

    std::vector<int> dp(1 << N);
    dp[0] = N * (N - 1) / 2 - M;
    for (int mask = 1; mask < (1 << N); mask++) {
        dp[mask] = inf;
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            dp[mask] = std::min(dp[mask], dp[mask & ~sub] + cnt[sub]);
        }
    }
    std::cout << dp[(1 << N) - 1] << "\n";

    return 0;
}