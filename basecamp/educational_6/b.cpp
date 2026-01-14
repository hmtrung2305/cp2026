#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> t(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i] >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int x = 0, y = 0;

    std::vector<int> c(8, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] < 4) {
            x += 100;
            if (c[a[i]] != -1 && t[i] - c[a[i]] <= 10) {
                x += 50;
            }
        } else {
            y += 100;
            if (c[a[i]] != -1 && t[i] - c[a[i]] <= 10) {
                y += 50;
            }
        }
        c[a[i]] = t[i];
    }

    std::cout << x << " " << y << "\n";

    return 0;
}