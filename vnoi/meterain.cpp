#include <bits/stdc++.h>

using i64 = long long;

struct Point {
    i64 x;
    i64 y;
    Point() : x(0), y(0) {}
    Point(i64 x_, i64 y_) : x(x_), y(y_) {}
};

i64 dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

i64 cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

struct Line {
    Point a;
    Point b;
    Line(Point a_ = Point(), Point b_ = Point()) : a(a_), b(b_) {}
};

bool pointOnLineLeft(const Point &p, const Line &l) {
    return cross(l.b - l.a, p - l.a) > 0;
}

bool pointOnSegment(const Point &p, const Line &l) {
    return cross(p - l.a, l.b - l.a) == 0 && std::min(l.a.x, l.b.x) <= p.x && p.x <= std::max(l.a.x, l.b.x)
        && std::min(l.a.y, l.b.y) <= p.y && p.y <= std::max(l.a.y, l.b.y);
}

bool pointInPolygon(const Point &a, const std::vector<Point> &p) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (pointOnSegment(a, Line(p[i], p[(i + 1) % n]))) {
            return false;
        }
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        if (u.x < a.x && v.x >= a.x && pointOnLineLeft(a, Line(v, u))) {
            t ^= 1;
        }
        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u, v))) {
            t ^= 1;
        }
    }
    return t == 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Point> P(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        P[i] = Point(x, y);
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;

        bool ans = pointInPolygon(Point(x, y), P);
        std::cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;
}