#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto solve = [&]() -> void {
        int n;
        std::cin >> n;

        std::vector<int> color(n * 2);
        for (int i = 0; i < 2 * n; ++i) {
            std::cin >> color[i];
            --color[i];
        }

        std::vector<std::vector<int>> adj(2 * n);
        for (int i = 1; i < 2 * n; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::vector<bool> vis(n, false);
        std::vector<int> ans;
        bool found = false;

        std::function<void(int)> dfs = [&](int u) -> void {
            std::cerr << u << ' ';
            vis[color[u]] = 1;
            ans.push_back(u);
            if ((int) ans.size() == n) {
                found = true;
                return;
            }
            for (auto v : adj[u]) {
                if (vis[color[v]]) continue;
                dfs(v);
                if (found == true) {
                    return;
                }
            }
            vis[color[u]] = 0;
            ans.pop_back();
        };
        std::cerr << '\n';

        for (int u = 0; u < 2 * n; ++u) {
            if (color[u] == 1) {
                found = false;
                ans.clear();
                dfs(u);
                if (found) {
                    std::cout << "ans = ";
                    for (int i = 0; i < n; ++i) {
                        std::cout << ans[i] + 1 << ' ';
                    }
                    std::cout << '\n';
                    return;
                }
            }
        }

        std::cout << "-1\n";
    };

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}