#include <bits/stdc++.h>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Point> P(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        P[i] = Point(X, Y);
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        std::map<std::pair<int, int>, int> cnt;
        for (int j = 0; j < N; j++) {
            if (j == i) {
                continue;
            }

            int dx = P[j].x - P[i].x;
            int dy = P[j].y - P[i].y;

            int g = std::__gcd(dx, dy);
            if (g != 0) {
                dx /= g;
                dy /= g;
            }
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }

            cnt[{dx, dy}]++;
        }

        for (auto [vec, x] : cnt) {
            auto [dx, dy] = vec;
            auto it = cnt.find({-dy, dx});
            if (it != cnt.end()) {
                ans += x * it->second;
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}