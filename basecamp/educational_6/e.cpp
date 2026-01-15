#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, x, y;
        std::cin >> a >> x >> y;
        a--;
        x--;
        y--;
        adj[x].push_back({y, a});
        adj[y].push_back({x, a});
    }

    std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<std::array<int, 2>>> h;
    for (int i = 0; i < n; i++) {
        h.push({c[i], i});
    }
    while (!h.empty()) {
        auto [dx, x] = h.top();
        h.pop();
        if (dx > c[x]) {
            continue;
        }
        for (auto [y, a] : adj[x]) {
            if (c[a] > c[x] + c[y]) {
                c[a] = c[x] + c[y];
                h.push({c[a], a});
            }
        }
    }

    std::cout << c[0] << "\n";

    return 0;
}