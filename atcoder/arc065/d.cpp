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

    int N, K, L;
    std::cin >> N >> K >> L;

    DSU d1(N), d2(N);
    for (int i = 0; i < K; i++) {
        int p, q;
        std::cin >> p >> q;
        p--;
        q--;
        d1.merge(p, q);
    }

    for (int i = 0; i < L; i++) {
        int r, s;
        std::cin >> r >> s;
        r--;
        s--;
        d2.merge(r, s);
    }

    std::map<std::array<int, 2>, int> m;
    for (int i = 0; i < N; i++) {
        m[{d1.find(i), d2.find(i)}]++;
    }

    for (int i = 0; i < N; i++) {
        std::cout << m[{d1.find(i), d2.find(i)}] << " \n"[i == N - 1];
    }

    return 0;
}