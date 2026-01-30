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

int main() {
    std::ios::since_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;



    return 0;
}