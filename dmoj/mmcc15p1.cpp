#include <bits/stdc++.h>

struct DSU {
    std::vector<int> siz;
    std::vector<int> f;
    std::vector<std::array<int, 2>> his;

    DSU() {}

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        siz.assign(n, 1);
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        his.push_back({x, y});
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int time() {
        return his.size();
    }

    void revert(int tm) {
        while (his.size() > tm) {
            auto [x, y] = his.back();
            his.pop_back();
            f[y] = y;
            siz[x] -= siz[y];
        }
    }
};

DSU dsu;
std::vector<std::pair<bool, int>> e;

void Init(int N) {
    dsu.init(N);
}

void AddEdge(int U, int V) {
    U--;
    V--;
    int tm = dsu.time();
    bool ok = dsu.merge(U, V);
    e.push_back({ok, tm});
}

void RemoveLastEdge() {
    auto [ok, tm] = e.back();
    e.pop_back();
    if (ok) {
        dsu.revert(tm);
    }
}

int GetSize(int U) {
    U--;
    return dsu.siz[dsu.find(U)];
}

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int n, q;
//     std::cin >> n >> q;

//     Init(n);

//     for (int i = 0; i < q; i++) {
//         int t;
//         std::cin >> t;

//         if (t == 1) {
//             int u, v;
//             std::cin >> u >> v;
//             AddEdge(u, v);
//         }
//         if (t == 2) { RemoveLastEdge(); }
//         if (t == 3) {
//             int u;
//             std::cin >> u;
//             std::cout << GetSize(u) << "\n";
//         }
//     }

//     return 0;
// }