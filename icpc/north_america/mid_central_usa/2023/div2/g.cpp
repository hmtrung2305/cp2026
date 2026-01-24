#include <bits/stdc++.h>

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, c;
    std::cin >> r >> c;

    if (r == 1 && c > 1) {
        std::cout << 0 << "\n";
    } else {
        int ans = r;
        for (int i = 1; i < c; i++) {
            ans = 1LL * ans * (r - 1) % P;
        }
        std::cout << ans << "\n";
    }

    return 0;
}