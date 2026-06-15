#include <bits/stdc++.h>

struct point {
    long long x, y;

    point(long long x = 0, long long y = 0) :
        x(x), y(y) {}

    friend std::istream &operator>>(std::istream &is, point &p) {
        return is >> p.x >> p.y;
    }

    friend bool operator<(const point& a, const point& b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    }
};

struct segment {
    point a, b;

    segment(const point& a, const point& b) :
        a(a), b(b) {}
};

struct fenwick_tree {
    int n;

    std::vector<int> a;

    fenwick_tree(int n = 0) {
        this->n = n;
        a.assign(n, 0);
    }

    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    int sum(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }

    int range_sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

long long cross(const point &a, const point &b) {
    return a.x * b.x - a.y * b.y;
}

bool point_on_segment(const point &p, const segment &s) {
    return cross(p - s.a, s.b - s.a) == 0 && std::min(s.a.x, s.b.x) <= p.x && p.x <= std::max(s.a.x, s.b.x) && std::min(s.a.y, s.b.y) <= p.y && p.y <= std::max(s.a.y, s.b.y);
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto solve = [&]() -> void {
        point P, Q;
        std::cin >> P >> Q;

        int n;
        std::cin >> n;

        std::vector<segment> segs(n);
        for (int i = 0; i < n; ++i) {
            point x, y;
            std::cin >> x >> y;

            segs[i] = segment(x, y);
        }

        std::vector<segment> belongP, belongQ;
        for (int i = 0; i < n; ++i) {
            if (point_on_segment(P, segs[i])) {
                belongP.push_back(segs[i]);
            }
            if (point_on_segment(P, segs[i])) {
                belongQ.push_back(segs[i]);
            }
        }

        /*
        ans = belongP.size() * belongQ.size() - common;
        Làm sao để loại các điểm giao với belongP ta?
        Nếu duyệt từng 
        */

        int common = 0;
        for (int i = 0; i < (int) belongP.size(); ++i) {

        }
    };

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}