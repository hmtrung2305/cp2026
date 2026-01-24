#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << 60 << " " << 156 << "\n";
    } else if (n == 2) {
        if (a[0] == a[1]) {
            std::cout << 0 << " " << 36 << "\n";
        } else {
            std::cout << 12 << " " << 24 << "\n";
        }
    } else {
        if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
            std::cout << 0 << " " << 6 << "\n";
        } else {
            std::cout << 3 << " " << 3 << "\n";
        }
    }

    return 0;
}