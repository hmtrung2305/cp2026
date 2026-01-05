#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> adj(2 * N - 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(N + i);
        adj[N + i].push_back(u);
        adj[v].push_back(N + i);
        adj[N + i].push_back(v);
    }

    int ans = N;
    for (int r = 0; r < 2 * N - 1; r++) {
        int res = 0;
        std::function<void(int, int, int)> dfs = [&](int x, int p, int d) {
            if (d > K && x < N) {
                res++;
            }
            for (auto y : adj[x]) {
                if (y == p) {
                    continue;
                }
                dfs(y, x, d + 1);
            }
        };
        dfs(r, -1, 0);
        ans = std::min(ans, res);
    }
    std::cout << ans << "\n";

    return 0;
}