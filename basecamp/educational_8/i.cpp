#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    i64 ans = 0;

    std::vector<std::vector<i64>> dp(n, std::vector<i64>(k + 1));
    std::function<void(int, int)> dfs = [&](int u, int p) {
        dp[u][0] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            for (int i = 0; i < k; i++) {
                ans += 1LL * dp[u][k - 1 - i] * dp[v][i];
            }
            for (int i = 0; i < k; i++) {
                dp[u][i + 1] += dp[v][i];
            }
        }
    };
    dfs(0, -1);

    std::cout << ans << "\n";

    return 0;
}