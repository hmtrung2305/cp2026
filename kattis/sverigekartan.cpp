#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, U;
    std::cin >> R >> C >> U;

    std::vector<std::string> g(R);
    for (int i = 0; i < R; i++) {
        std::cin >> g[i];
    }

    DSU dsu(R * C);
    std::array<int, 2> s;
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (g[x][y] == '.') {
                continue;
            }
            if (g[x][y] == 'S') {
                s = {x, y};
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                    continue;
                }
                if (g[nx][ny] != '.') {
                    dsu.merge(x * C + y, nx * C + ny);
                }
            }
        }
    }

    std::cout << dsu.size(s[0] * C + s[1]) << "\n";
    for (int i = 0; i < U; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;

        g[x][y] = '#';
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                continue;
            }
            if (g[nx][ny] != '.') {
                dsu.merge(x * C + y, nx * C + ny);
            }
        }
        std::cout << dsu.size(s[0] * C + s[1]) << "\n";
    }

    return 0;
}