#include <bits/stdc++.h>

void solve() {
    int n, i;
    double p;
    std::cin >> n >> p >> i;

    if (p == 0) {
        std::cout << 0 << "\n";
        return;
    }

    double q = 1 - p;
    double ans = p * pow(q, i - 1) / (1.0 - pow(q, n));
    std::cout << std::fixed << std::setprecision(4) << ans << "\n";
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