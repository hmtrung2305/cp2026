#include <bits/stdc++.h>

using i64 = long long;

struct Point {
    i64 x;
    i64 y;
    Point() : x(0), y(0) {}
    Point(i64 x_, i64 y_) : x(x_), y(y_) {}
};

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

i64 cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

i64 area(Point a, Point b, Point c) {
    return std::llabs(cross(b - a, c - a));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<Point> P(2 * n);
    for (int i = 0; i < n; i++) {
        i64 x, y;
        std::cin >> x >> y;
        P[i] = Point(x, y);
        P[n + i] = Point(x, y);
    }

    std::vector<i64> sum(n);
    if (k > 1) {
        i64 s = 0;
        for (int i = 2; i <= k; i++) {
            s += area(P[0], P[i - 1], P[i]);
        }
        sum[0] = s;
        for (int i = k + 1; i < k + n; i++) {
            s -= area(P[i - 1], P[i - k], P[i - k - 1]);
            s += area(P[i - k], P[i - 1], P[i]);
            sum[i - k] = s;
        }
    }


    i64 ans = 0;
    for (int i = 0, j = i + k + 1; i < n; i++) {
        j = std::max(j, i + k + 1);
        i64 mx = area(P[i], P[i + k], P[j]);
        while (j + 1 < n + i && area(P[i], P[i + k], P[j + 1]) >= mx) {
            mx = area(P[i], P[i + k], P[j + 1]);
            j++;
        }
        ans = std::max(ans, sum[i] + mx);
    }
    std::cout << std::fixed << std::setprecision(1) << ans / 2.0 << "\n";

    return 0;
}