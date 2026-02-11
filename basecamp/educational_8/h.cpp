#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    std::vector<int> f(n, -1);
    std::queue<int> q;
    q.push(0);
    f[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (f[y] == -1) {
                f[y] = f[x] + 1;
                q.push(y);
            }
        }
    }

    std::vector<int> g(n, -1);
    for (int i = 1; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
            g[i] = 0;
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (g[y] == -1) {
                g[y] = g[x] + 1;
                q.push(y);
            }
        }
    }

    int ans = 0;
    std::function<void(int, int)> dfs = [&](int x, int p) {
        if (f[x] >= g[x]) {
            ans++;
            return;
        }
        for (int y : adj[x]) {
            if (y == p) {
                continue;
            }
            dfs(y, x);
        }
    };
    dfs(0, -1);

    std::cout << ans << "\n";

    return 0;
}