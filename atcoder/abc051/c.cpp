#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    int n = ty - sy;
    int m = tx - sx;

    std::cout << std::string(n, 'U');
    std::cout << std::string(m, 'R');

    std::cout << std::string(n, 'D');
    std::cout << std::string(m, 'L');

    std::cout << "D";
    std::cout << std::string(m + 1, 'R');
    std::cout << std::string(n + 1, 'U');
    std::cout << "L";

    std::cout << "U";
    std::cout << std::string(m + 1, 'L');
    std::cout << std::string(n + 1, 'D');
    std::cout << "R\n";

    return 0;
}