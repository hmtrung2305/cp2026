#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int p;
        std::cin >> p;
        p--;
        if (p != -1) {
            adj[p].push_back(i);
        }
    }

    std::vector<int> dp(n, 1);
    std::function<void(int, int)> dfs = [&](int x, int p) {
        int mx1 = -1, mx2 = -1;
        for (int y : adj[x]) {
            if (p != x) {
                dfs(y, x);
                if (dp[y] >= mx1) {
                    mx2 = mx1;
                    mx1 = dp[y];
                } else {
                    mx2 = std::max(mx2, dp[y]);
                }
            }
        }
        dp[x] = std::max(dp[x], mx1 + (mx2 == mx1));
    };
    dfs(0, -1);
    
    std::cout << dp[0] << "\n";
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