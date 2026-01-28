#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    while (std::cin >> n && n) {
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<std::pair<int, double>> c;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (a[i] >= a[j] + a[k] || a[j] >= a[i] + a[k] || a[k] >= a[i] + a[j]) {
                        continue;
                    }
                    int mask = (1 << i) | (1 << j) | (1 << k);
                    double p = (a[i] + a[j] + a[k]) / 2.0;
                    double x = std::sqrt(p * (p - a[i]) * (p - a[j]) * (p - a[k]));
                    c.push_back({mask, x});
                }
            }
        }

        std::vector<double> dp(1 << n);
        for (int mask = 0; mask < (1 << n); mask++) {
            for (auto [sub, area] : c) {
                if ((mask & sub) == 0) {
                    dp[mask | sub] = std::max(dp[mask | sub], dp[mask] + area);
                }
            }
        }
        std::cout << std::fixed << std::setprecision(4) << *std::max_element(dp.begin(), dp.end()) << "\n";
    }

    return 0;
}