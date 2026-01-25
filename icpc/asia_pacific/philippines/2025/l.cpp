#include <bits/stdc++.h>

constexpr int P = 1006903069;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int ka;
    std::cin >> ka;

    std::vector<std::map<int, int>> a(n);
    for (int i = 0; i < ka; i++) {
        int x, y, v;
        std::cin >> x >> y >> v;
        x--;
        y--;
        a[x][y] = v;
    }

    int kb;
    std::cin >> kb;

    int ans = 0;

    for (int i = 0; i < kb; i++) {
        int x, y, v;
        std::cin >> x >> y >> v;
        x--;
        y--;
        if (a[y].find(x) != a[y].end()) {
            ans = (ans + 1LL * a[y][x] * v % P) % P;
        }
    }

    std::cout << ans << "\n";

    return 0;
}