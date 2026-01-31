#include <bits/stdc++.h>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}
};

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

int cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}



int main() {
    std::ios::since_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Point> P(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        P[i] = Point(x, y);
    }

    if (n == 0) {
        std::cout << 1 << "\n";
        return 0;
    }
    if (n == 1) {
        std::cout << 2 << "\n";
        return 0;
    }

    for () {

    }

    return 0;
}