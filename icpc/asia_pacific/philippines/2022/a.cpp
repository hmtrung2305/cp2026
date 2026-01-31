#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::cin >> x;

    if (x <= -3) {
        std::cout << -((x + 4) * (x + 4)) + 8 << "\n";
    } else if (x <= 2) {
        std::cout << -2 * x + 1 << "\n";
    } else {
        std::cout << x * x * x + -14 * x + 17 << "\n";
    }

    return 0;
}