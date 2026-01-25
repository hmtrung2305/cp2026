#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<std::array<int, 4>> e(M);
    for (int i = 0; i < M; i++) {
        int u, v, p, h;
        std::cin >> u >> v >> p >> h;
        u--;
        v--;
        e[i] = {u, v, p, h};
    }

    std::sort(e.begin(), e.end(),
        [&](std::array<int, 4> x, std::array<int, 4> y) {
            return x[2] < y[2];
        });

    std::vector<std::vector<i64>> dis(N, std::vector<i64>(N, inf));
    for (int i = 0; i < N; i++) {
        dis[i][i] = 0;
    }

    std::vector<int> ps;
    std::vector<std::vector<i64>> f1;
    for (auto [u, v, p, h] : e) {
        ps.push_back(p);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][u] + h + dis[v][j]);
            }
        }
        std::vector<i64> f(N);
        for (int i = 0; i < N; i++) {
            f[i] = *std::max_element(dis[i].begin(), dis[i].end());
        }
        f1.push_back(f);
    }

    std::vector<std::array<i64, 3>> f2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (f1[j][i] == inf) {
                continue;
            }
            f2.push_back({f1[j][i], ps[j], i});
        }
    }
    std::sort(f2.begin(), f2.end());
    for (int i = 1; i < f2.size(); i++) {
        if (f2[i][1] > f2[i - 1][1]) {
            f2[i][1] = f2[i - 1][1];
            f2[i][2] = f2[i - 1][2];
        } else if (f2[i][1] == f2[i - 1][1]) {
            f2[i][2] = std::min(f2[i][2], f2[i - 1][2]);
        }
    }

    for (int i = 0; i < Q; i++) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int u;
            i64 h;
            std::cin >> u >> h;
            u--;

            int lo = 0, hi = M;
            while (lo < hi) {
                int x = (lo + hi) >> 1;
                if (f1[x][u] <= h) {
                    hi = x;
                } else {
                    lo = x + 1;
                }
            }
            std::cout << (lo < M ? ps[lo] : -1) << "\n";
        } else {
            i64 h;
            std::cin >> h;

            if (f2[0][0] > h) {
                std::cout << -1 << " " << -1 << "\n";
                continue;
            }

            int lo = 0, hi = f2.size() - 1;
            while (lo < hi) {
                int x = (lo + hi + 1) >> 1;
                if (f2[x][0] <= h) {
                    lo = x;
                } else {
                    hi = x - 1;
                }
            }

            std::cout << f2[lo][2] + 1 << " " << f2[lo][1] << "\n";
        }
    }

    return 0;
}