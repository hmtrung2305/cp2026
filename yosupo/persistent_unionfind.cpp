#include <bits/stdc++.h>

struct DSU {
    std::vector<int> siz;
    std::vector<int> f;
    std::vector<std::array<int, 2>> his;

    DSU(int n) : siz(n + 1, 1), f(n + 1) {
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::array<int, 4>> qry(Q + 1);
    std::vector<std::vector<int>> adj(Q + 1);
    for (int i = 1; i <= Q; i++) {
        int op, k, u, v;
        std::cin >> op >> k >> u >> v;
        k++;

        qry[i] = {op, k, u, v};
        adj[k].push_back(i);
    }

    std::vector<bool> ans(Q + 1);
    DSU dsu(N);

    std::function<void(int)> dfs = [&](int x) {
        if (qry[x][0] == 0) {
            dsu.merge(qry[x][2], qry[x][3]);
        } else {
            if (dsu.find(qry[x][2]) == dsu.find(qry[x][3])) {
                ans[x] = 1;
            }
        }

        for (int y : adj[x]) {
            dfs(y);
        }

        if (qry[x][0] == 0) {
            dsu.revert(dsu.time() - 1);
        }
    };
    dfs(0);

    for (int i = 1; i <= Q; i++) {
        if (qry[i][0]) {
            std::cout << ans[i] << "\n";
        }
    }

    return 0;
}