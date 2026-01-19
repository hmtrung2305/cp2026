#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int s1 = 0;
    for (int i = 0; i < n; i++) {
        s1 += std::count(s[i].begin(), s[i].end(), '.');
    }

    std::vector<std::vector<bool>> f(n + 2, std::vector<bool>(m + 2));
    std::vector<std::vector<bool>> g(n + 2, std::vector<bool>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1][j - 1] == '.') {
                f[i][j] = (i == 1 && j == 1 ? 1 : f[i][j - 1] | f[i - 1][j]);
            }
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            if (s[i - 1][j - 1] == '.') {
                g[i][j] = (i == n && j == m ? 1 : g[i][j + 1] | g[i + 1][j]);
            }
        }
    }

    if (!f[n][m]) {
        std::cout << 1LL * s1 * (s1 - 1) / 2 << "\n";
        return 0;
    }

    std::vector<std::vector<bool>> c(n + 2, std::vector<bool>(m + 2));
    std::vector<std::vector<bool>> r(n + 2, std::vector<bool>(m + 2));
    for (int x = 1, y = 1; x != n || y != m; ) {
        c[x][y] = 1;
        if (g[x + 1][y]) {
            x++;
        } else {
            y++;
        }
    }
    c[n][m] = 1;
    for (int x = 1, y = 1; x != n || y != m; ) {
        r[x][y] = 1;
        if (g[x][y + 1]) {
            y++;
        } else {
            x++;
        }
    }
    r[n][m] = 1;

    int s2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s2 += c[i][j] && r[i][j];
        }
    }

    i64 ans = s2 * (s1 - 1) - s2 * (s2 - 1) / 2;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (c[x][y] && !r[x][y]) {
                int sx = x - 1;
                int sy = y + 1;
                while (!f[sx][sy] || !g[sx][sy]) {
                    sx--;
                    sy++;
                }

                int s3 = 0;
                auto add = [&](int rx, int ry, int v) {
                    s3 += v * (r[rx][ry] && !c[rx][ry]);
                };

                for (int i = sx, j = sy; i != 1 || j != 1; ) {
                    add(i, j, 1);
                    if (f[i][j - 1]) {
                        j--;
                    } else {
                        i--;
                    }
                }
                for (int i = sx, j = sy; i != n || j != m; ) {
                    add(i, j, 1);
                    if (f[i + 1][j]) {
                        i++;
                    } else {
                        j++;
                    }
                }
                add(1, 1, 1);
                add(n, m, 1);
                add(sx, sy, -1);

                ans += s3;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}