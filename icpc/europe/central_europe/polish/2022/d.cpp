#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> siz(n, 0);
    int total_leaves = 0;
    std::function<void(int, int)> dfs1 = [&](int u, int p) -> void {
        siz[u] = 1;
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u);
            siz[u] += siz[v];
        }
        if (siz[u] == 1) {
            ++total_leaves;
        }
    };
    dfs1(0, -1);

    std::vector<int> cnt(n + 1, 0);
    std::function<int(int, int)> dfs2 = [&](int u, int p) -> int {
        int leaves = 0;
        for (auto v : adj[u]) {
            if (v == p) continue;
            leaves += dfs2(v, u);

        }
        if (siz[u] == 1) {
            ++leaves;
        }
        cnt[siz[u]] += leaves;
        return leaves;
    };
    dfs2(0, -1);

    std::vector<int> ans;
    for (int s = 1; s <= n; ++s) {
        if (cnt[s] == total_leaves) {
            ans.push_back(s);
        }
    }

    std::cout << ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}