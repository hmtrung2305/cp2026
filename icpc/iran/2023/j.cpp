#include <bits/stdc++.h>

struct LazySegmentTree {
    int n;
    std::vector<int> info, lazy;

    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_) {
        n = n_;
        info.assign(n << 4, 0);
        lazy.assign(n << 4, 0);
    }

    void push(int p) {
        if (lazy[p] != 0) {
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            info[p << 1] += lazy[p];
            info[p << 1 | 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    void rangeUpdate(int l, int r, int p, int lp, int rp) {
        if (lp >= r || rp <= l) {
            return;
        }
        if (lp >= l && rp <= r) {
            info[p]++;
            lazy[p]++;
            return;
        }
        push(p);
        int m = (lp + rp) / 2;
        rangeUpdate(l, r, p << 1, lp, m);
        rangeUpdate(l, r, p << 1 | 1, m, rp);
        info[p] = std::min(info[p << 1], info[p << 1 | 1]);
    }

    int rangeQuery(int l, int r, int p, int lp, int rp) {
        if (lp >= r || rp <= l) {
            return 1E9;
        }
        if (lp >= l && rp <= r) {
            return info[p];
        }
        push(p);
        int m = (lp + rp) / 2;
        int lhs = rangeQuery(l, r, p << 1, lp, m);
        int rhs = rangeQuery(l, r, p << 1 | 1, m, rp);
        return std::min(lhs, rhs);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        a[i] = {c, i};
    }

    std::sort(a.begin(), a.end(), std::greater<std::array<int, 2>>());

    LazySegmentTree seg(n - k + 1);

    std::vector<int> ans(n);
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j][0] == a[i][0]) {
            ans[a[j][1]] = seg.rangeQuery(std::max(0, a[j][1] - k + 1), std::min(a[j][1] + 1, n - k + 1), 1, 0, n - k + 1);
            j++;
        }
        for (int l = i; l < j; l++) {
            seg.rangeUpdate(std::max(0, a[l][1] - k + 1), std::min(a[l][1] + 1, n - k + 1), 1, 0, n - k + 1);
        }
        i = j;
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}