#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n & 1) {
        std::cout << n / 2 << "\n";
        return 0;
    }

    int x = n / 2;
    while (std::__gcd(x, n) != 1) {
        x--;
    }
    std::cout << x << "\n";

    return 0;
}