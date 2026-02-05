#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x;
    std::cin >> x;

    i64 a = x / 11;
    i64 b = x % 11;

    std::cout << a * 2 + (b > 6 ? 2 : (b == 0 ? 0 : 1)) << "\n";

    return 0;
}