#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    if (n & 1) {
        std::cout << 1LL * (n - 1) * (n + 1) / 2 << "\n";
    } else {
        std::cout << 1LL * n * n / 2 << "\n";
    }
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