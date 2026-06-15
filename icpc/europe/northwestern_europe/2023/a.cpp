#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a[4] = {};
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + 4);

    std::cout << a[0] * a[2] << "\n";

    return 0;
}