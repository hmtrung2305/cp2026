#include <bits/stdc++.h>

int main() {
    freopen("FLOWER.INP", "r", stdin);
    freopen("FLOWER.OUT", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int s = 0;
    for (int i = 1; i < n; i++) {
        s += std::abs(a[i] - a[i - 1]);
    }

    int ans = s;
    for (int i = 1; i < n - 1; i++) {
        ans = std::min(ans, s - std::abs(a[i - 1] - a[i]) - std::abs(a[i] - a[i + 1]) + std::abs(a[i - 1] - a[i + 1]));
    }
    std::cout << ans << "\n";

    return 0;
}