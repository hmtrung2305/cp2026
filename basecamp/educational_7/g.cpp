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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        e[i] = {a, b, c};
    }

    std::sort(e.begin(), e.end(),
        [&](std::array<int, 3> x, std::array<int, 3> y) {
            return x[2] < y[2];
        });

    int ans = 0;
    DSU dsu(n);
    for (auto [x, y, w] : e) {
        if (dsu.merge(x, y)) {
            ans += w;
        }
    }
    std::cout << ans << "\n";

    return 0;
}