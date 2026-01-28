#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> pre(n + 1, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            pre[i + 1][j] = pre[i][j] + x;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int s = 0;
            for (int r = 0, l = 0; r < m; r++) {
                s += pre[j][r] - pre[i - 1][r];
                while (l <= r && s > k) {
                    s -= pre[j][l] - pre[i - 1][l];
                    l++;
                }
                ans = std::max(ans, (r - l + 1) * (j - i + 1));
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}