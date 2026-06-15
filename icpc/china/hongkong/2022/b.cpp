#include <bits/stdc++.h>

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> p(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> p[i][j];
        }
    }
    std::vector<std::vector<int>> q(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> q[i][j];
        }
    }

    std::vector<std::vector<int>> l(n + 1, std::vector<int>(m + 1));
    std::vector<std::vector<int>> u(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            l[i][j] = (l[i][j - 1] + p[i - 1][j - 1]) % P;
            u[i][j] = (u[i - 1][j] + q[i - 1][j - 1]) % P;
        }
    }
    std::vector<std::vector<int>> r(n + 2, std::vector<int>(m + 2));
    std::vector<std::vector<int>> d(n + 2, std::vector<int>(m + 2));
    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            r[i][j] = (r[i][j + 1] + p[i - 1][j - 1]) % P;
            d[i][j] = (d[i + 1][j] + q[i - 1][j - 1]) % P;
        }
    }

    int ans = 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = (ans + 1LL * l[i][j - 1] * u[i - 1][j] % P * d[i][j + 1] % P * r[i + 1][j] % P) % P;
        }
    }
    std::cout << ans << "\n";

    return 0;
}