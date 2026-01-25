#include <bits/stdc++.h>

struct FenwickTree {
    int n;
    std::vector<int> a;

    FenwickTree(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n + 1, 0);
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

    int rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        P[i]--;
    }

    FenwickTree fen(N);
    std::vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        pos[P[i]] = i;
        fen.add(i, 1);
    }

    std::vector<int> ans(N);
    int lst = 0;
    for (int i = N - 1; i >= 0; i--) {
        int x = (lst <= pos[i] ? fen.rangeSum(lst, pos[i]) : fen.rangeSum(lst, N) + fen.sum(pos[i]));
        ans[i] = i - x + 1;
        fen.add(pos[i], -1);
        lst = pos[i];
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }

    return 0;
}