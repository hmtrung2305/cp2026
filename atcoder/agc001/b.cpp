#include <bits/stdc++.h>

using i64 = long long;

i64 f(i64 x, i64 y) {
    if (x > y) {
        std::swap(x, y);
    }
    i64 d = y / x;
    if (y % x == 0) {
        return (2 * d - 1) * x;
    }
    return 2 * d * x + f(x, y % x);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, X;
    std::cin >> N >> X;

    std::cout << N + f(X, N - X) << "\n";

    return 0;
}