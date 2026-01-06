#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> dis(N, std::vector<int>(N, 1E9));
    for (int i = 0; i < N; i++) {
        dis[i][i] = 0;
    }
    std::vector<std::array<int, 3>> vec;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        vec.push_back({a, b, c});
        dis[a][b] = dis[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int ans = 0;
    for (auto [x, y, w] : vec) {
        bool ok = true;
        for (int u = 0; u < N; u++) {
            for (int v = u + 1; v < N; v++) {
                if (dis[u][x] + dis[y][v] + w == dis[u][v] || dis[u][y] + dis[x][v] + w == dis[v][u]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        ans += ok;
    }
    std::cout << ans << "\n";

    return 0;
}