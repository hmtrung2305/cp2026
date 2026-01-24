#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::array<bool, 10>> d(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            d[i][x] = 1;
        }
    }

    if (d[0][7] && d[1][7] && d[2][7]) {
        std::cout << "777\n";
        return 0;
    }
    std::cout << "0\n";

    return 0;
}