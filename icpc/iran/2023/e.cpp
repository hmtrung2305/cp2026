#include <bits/stdc++.h>

using i64 = long long;

struct Point {
    i64 x, y;
    Point(i64 x_ = 0, i64 y_ = 0) : x(x_), y(y_) {}
};

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

i64 cross(Point a, Point b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

int sgn(i64 x) {
    return (x > 0 ? 1 : (x < 0 ? -1 : 0));
}

int ori(Point a, Point b, Point c) {
    return sgn(cross(b - a, c - b));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Point> p(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        p[i] = Point(x, y);
    }

    auto work = [&](bool rev) {
        if (rev) {
            std::reverse(p.begin(), p.end());
            for (int i = 0; i < N; i++) {
                p[i].x = -p[i].x;
            }
        }

        std::vector<int> res(N, -1);
        std::vector<int> stk{0};
        for (int i = 1; i < N - 1; i++) {
            while (stk.size() > 1 && ori(p[stk[stk.size() - 2]], p[stk.back()], p[i]) != 1) {
                stk.pop_back();
            }
            res[i] = stk.back();
            stk.push_back(i);
        }

        if (rev) {
            std::reverse(p.begin(), p.end());
            std::reverse(res.begin(), res.end());
            for (int i = 0; i < N; i++) {
                p[i].x = -p[i].x;
            }
            for (int i = 0; i < N; i++) {
                res[i] = N - 1 - res[i];
            }
        }

        return res;
    };

    std::vector<int> L = work(0);
    std::vector<int> R = work(1);

    double ans = 0;
    for (int i = 1; i < N - 1; i++) {
        double h = p[i].y;
        double l = p[i].x - p[i].y * (p[i].x - p[L[i]].x) / double(p[i].y - p[L[i]].y);
        double r = p[i].x - p[i].y * (p[R[i]].x - p[i].x) / double(p[R[i]].y - p[i].y);
        ans = std::max(ans, (r - l) * h / 2.0);
    }

    std::cout << std::fixed << std::setprecision(7) << ans << "\n";

    return 0;
}