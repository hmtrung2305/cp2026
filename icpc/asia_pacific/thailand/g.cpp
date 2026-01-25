#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int, int>>> adj(N);
    for (int i = 1; i < N; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<std::array<i64, 3>> a(N);
    for (int i = 0; i < N; i++) {
        i64 x, y, z;
        std::cin >> x >> y >> z;
        a[i] = {x, y, z};
    }

    i64 ans = 0;

    std::vector<std::array<i64, 8>> dp(N);
    std::function<void(int, int)> dfs = [&](int x, int p) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                if (i >> j & 1) {
                    dp[x][i] += a[x][j];
                } else {
                    dp[x][i] -= a[x][j];
                }
            }
        }

        for (auto [y, w] : adj[x]) {
            if (y == p) {
                continue;
            }
            dfs(y, x);

            for (int i = 0; i < 8; i++) {
                ans = std::max(ans, dp[x][i] + dp[y][i ^ 7] + w);
            }
            for (int i = 0; i < 8; i++) {
                dp[x][i] = std::max(dp[x][i], dp[y][i] + w);
            }
        }
    };
    dfs(0, -1);

    std::cout << ans << "\n";

    return 0;
}