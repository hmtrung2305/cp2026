#include <bits/stdc++.h>

using i64 = long long;

struct Point {
    i64 x;
    i64 y;
    Point() : x(0), y(0) {}
    Point(i64 x_, i64 y_) : x(x_), y(y_) {}
};

i64 cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

i64 area(Point a, Point b, Point c) {
    return std::llabs(cross(b - a, c - a));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Point> P(2 * N);
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        P[i] = Point(x, y);
        P[i + N] = P[i];
    }

    i64 ans = 0;
    for (int a = 0, b = 1, c = 2, d = 3; a < N; a++) {
        b = std::max(b, a + 1);
        c = std::max(c, a + 2);
        d = std::max(d, a + 3);

        while (true) {

            while (b + 1 < c) {
                i64 cur = area(P[a], P[b], P[c]);
                i64 nxt = area(P[a], P[b + 1], P[c]);
                if (nxt > cur) {
                    b++;
                } else {
                    break;
                }
            }

            while (d + 1 < a + N) {
                i64 cur = area(P[c], P[d], P[a]);
                i64 nxt = area(P[c], P[d + 1], P[a]);
                if (nxt > cur) {
                    d++;
                } else {
                    break;
                }
            }

            i64 cur = area(P[a], P[b], P[c]) + area(P[c], P[d], P[a]);
            ans = std::max(ans, cur);

            if (c + 1 >= a + N - 1) {
                break;
            }
            i64 nxt = area(P[a], P[b], P[c + 1]) + area(P[c + 1], P[d], P[a]);
            if (nxt > cur) {
                c++;
            } else {
                break;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(1) << ans / 2.0 << "\n";

    return 0;
}