#include <bits/stdc++.h>

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

constexpr int inf = 2E9;

struct Info {
    int min1, min2;
    int cnt1;

    Info() : min1(inf), min2(inf), cnt1(0) {}
    Info(int x) : min1(x), min2(inf), cnt1(1) {}
};

Info operator+(Info a, Info b) {
    Info c;
    if (a.min1 < b.min1) {
        c.min1 = a.min1;
        c.cnt1 = a.cnt1;
        c.min2 = std::min(a.min2, b.min1);
    } else if (a.min1 > b.min1) {
        c.min1 = b.min1;
        c.cnt1 = b.cnt1;
        c.min2 = std::min(b.min2, a.min1);
    } else {
        c.min1 = a.min1;
        c.cnt1 = a.cnt1 + b.cnt1;
        c.min2 = std::min(a.min2, b.min2);
    }
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = Info(x);
    }

    SegmentTree<Info> seg(n);
    seg.init(a);

    int m;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        int t, l, r;
        std::cin >> t >> l >> r;
        l--;

        if (t == 1) {
            Info res = seg.rangeQuery(l, r);
            if (res.cnt1 > 1) {
                std::cout << (res.min1 * 2 <= k ? "Yes" : "No") << "\n";
            } else {
                std::cout << (res.min1 + res.min2 <= k ? "Yes" : "No") << "\n";
            }
        } else {
            seg.modify(l, Info(r));
        }
    }

    return 0;
}