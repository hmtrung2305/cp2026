#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b;
    std::cin >> n >> a >> b;

    int x = a + b - n;
    int y = b - x;
    int z = a - x;

    std::cout << x << " " << y << " " << z << "\n";

    return 0;
}