#include <bits/stdc++.h>

constexpr int inf = 100;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        std::vector<int> x(n);
        for (int j = 0; j < n; j++) {
            std::cin >> x[j];
        }

        int mx = *std::max_element(x.begin(), x.end());
        int mn = *std::min_element(x.begin(), x.end());

        double ans = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (x[j] != mx && x[j] != mn) {
                ans += x[j];
                cnt++;
            }
        }
        if (cnt > 0) {
            ans /= cnt;
        }

        std::cout << std::fixed << std::setprecision(2) << ans << " \n"[i == m - 1];
    }

    return 0;
}