#include <bits/stdc++.h>

struct FenwickTree {
    int n;
    std::vector<int> a;

    FenwickTree(int n_) {
        n = n_;
        a.assign(n, 0);
    }

    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    int sum(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            res += a[i - 1];
        }
        return res;
    }
};

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
        p[i]--;
    }

    int K = N - 1;
    while (K > 0 && p[K] > p[K - 1]) {
        K--;
    }

    std::cout << K << "\n";

    FenwickTree fen(N);
    for (int i = K; i < N; i++) {
        fen.add(p[i], 1);
    }

    for (int i = 0; i < K; i++) {
        int ans = K - 1 - i + fen.sum(p[i]);
        std::cout << ans << " \n"[i == K - 1];
        fen.add(p[i], 1);
    }

    return 0;
}