#include <bits/stdc++.h>

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> dp{0};
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;

        dp.resize(dp.size() + a, inf);
        for (int j = dp.size() - 1; j >= 0; j--) {
            dp[j] = std::min(dp[j] + b, j < a ? inf : dp[j - a]);
        }
    }

    int ans = inf;
    for (int i = 0; i < dp.size(); i++) {
        ans = std::min(ans, std::max(i, dp[i]));
    }
    std::cout << ans << "\n";

    return 0;
}