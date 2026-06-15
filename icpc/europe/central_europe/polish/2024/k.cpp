#include <bits/stdc++.h>

void solve() {
    int a[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> a[i][j];
        }
    }

    int w = a[1][0] - a[0][0];
    if (w < 2 || a[1][1] - a[0][1] != w || a[0][0] % w == 0 || a[0][0] + 1 != a[0][1]) {
        std::cout << -1 << "\n";
        return;
    }
    std::cout << 100000 << " " << w << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}