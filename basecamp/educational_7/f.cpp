#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--;
    t--;

    std::vector<std::vector<bool>> a(n, std::vector<bool>(n));
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        a[u][v] = 1;
        a[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto work = [&](int src) {
        std::vector<int> dis(n, -1);
        std::queue<std::pair<int, int>> q;
        q.push({src, 0});
        while (!q.empty()) {
            auto [x, d] = q.front();
            q.pop();
            if (dis[x] != -1) {
                continue;
            }
            dis[x] = d;
            for (int y : adj[x]) {
                q.push({y, d + 1});
            }
        }
        return dis;
    };

    auto f = work(s);
    auto g = work(t);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j]) {
                continue;
            }
            if ((f[i] == -1 && g[j] == -1) || (g[i] == -1 && f[j] == -1)) {
                ans++;
                continue;
            }
            assert(f[i] != -1 && g[i] != -1 && f[j] != -1 && g[j] != -1);
            if (std::min(f[i] + 1 + g[j], f[j] + 1 + g[i]) >= f[t]) {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}