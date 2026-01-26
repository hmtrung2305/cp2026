#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    for (int t = 0; t < 2; t++) {
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[0]) {
                for (int x = i, y = 0; y < m; y++, x = (x + 1) % n) {
                    if (a[x] != b[y]) {
                        ok = 0;
                    }
                }
                break;
            }
        }
        if (ok) {
            std::cout << "1\n";
            return 0;
        }
        std::reverse(a.begin(), a.end());
    }
    std::cout << "0\n";

    return 0;
}