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

i64 square(const Point &p) {
    return dot(p, p);
}

double length(const Point &p) {
    return std::sqrt(square(p));
}

double length(const Line &l) {
    return length(l.a - l.b);
}

double distance(const Point &a, const Point &b) {
    return length(a - b);
}

double distancePL(const Point &p, const Line &l) {
    return std::abs(cross(l.a - l.b, l.a - p)) / length(l);
}

double distancePS(const Point &p, const Line &l) {
    if (dot(p - l.a, l.b - l.a) < 0) {
        return distance(p, l.a);
    }
    if (dot(p - l.b, l.a - l.b) < 0) {
        return distance(p, l.b);
    }
    return distancePL(p, l);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int xI, yI;
    std::cin >> xI >> yI;

    Point P = Point(xI, yI);

    int n, k;
    std::cin >> n >> k;

    std::vector<Line> L(n);
    for (int i = 0; i < n; i++) {
        int xA, yA, xB, yB;
        std::cin >> xA >> yA >> xB >> yB;

        L[i] = Line(Point(xA, yA), Point(xB, yB));
    }


    auto check = [&](int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += distancePS(P, L[i]) <= x;
        }
        return cnt <= k;
    };

    int lo = 0, hi = 2E6;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    std::cout << lo << "\n";

    return 0;
}