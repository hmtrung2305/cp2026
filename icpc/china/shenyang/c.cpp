#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    std::cin >> x >> y;

    if (y == 0 || y == 1) {
        std::cout << 4 - x << "\n";
    // } else if (y == 2) {
        std::cout << 6 - 2 * x << "\n";
    }

    return 0;
}