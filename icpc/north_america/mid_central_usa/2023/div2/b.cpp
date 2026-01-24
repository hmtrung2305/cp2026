#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<char, int> m;
    m['('] = 1;
    m['['] = 2;
    m['{'] = 3;
    m[')'] = -1;
    m[']'] = -2;
    m['}'] = -3;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        a[i] = m[c];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    std::vector<int> stk;
    std::function<void(int, int)> dfs = [&](int x, int p) {
        if (a[x] > 0) {
            stk.push_back(a[x]);
        }
        if (a[x] < 0) {
            if (stk.empty() || stk.back() != -a[x]) {
                return;
            }
            stk.pop_back();
            ans += stk.empty();
        }

        for (int y : adj[x]) {
            if (y == p) {
                continue;
            }
            dfs(y, x);
        }

        if (a[x] < 0) {
            stk.push_back(-a[x]);
        } else {
            stk.pop_back();
        }
    };

    for (int i = 0; i < n; i++) {
        dfs(i, -1);
    }

    std::cout << ans << "\n";

    return 0;
}