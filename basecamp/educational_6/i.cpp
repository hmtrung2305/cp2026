#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    std::cin >> n >> p;

    std::vector<int> m(n);
    for (int i = 0; i < n; i++) {
        std::cin >> m[i];
    }

    int tot = std::accumulate(m.begin(), m.end(), 0);

    std::vector<int> sum(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) {
        int i = __builtin_ctz(mask);
        sum[mask] = sum[mask ^ (1 << i)] + m[i];
    }

    std::vector<int> dp(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            if (sum[sub] == 1000) {
                dp[mask] = std::max(dp[mask], dp[mask ^ sub] + 1);
            }
        }
    }

    int ans = tot - (1000 - p) * dp[(1 << n) - 1];
    std::cout << ans << "\n";

    return 0;
}