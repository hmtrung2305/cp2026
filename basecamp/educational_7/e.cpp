#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    std::vector<int> dis(n, -1);

    std::deque<std::pair<int, int>> dq;
    dq.push_back({0, 0});
    while (!dq.empty()) {
        auto [x, d] = dq.front();
        dq.pop_front();

        if (dis[x] != -1) {
            continue;
        }
        dis[x] = d;

        for (int y : adj[x]) {
            if (dis[y] == -1) {
                dq.push_front({y, d});
            }
        }
        for (int y : radj[x]) {
            if (dis[y] == -1) {
                dq.push_back({y, d + 1});
            }
        }
    }

    std::cout << dis[n - 1] << "\n";

    return 0;
}