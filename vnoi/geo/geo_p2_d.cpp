#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    i64 ans = 0;
    for (int i = 2; i < n; i++) {
        std::vector<double> slope;
        for (int j = 0; j < i; j++) {
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            slope.push_back(dy == 0 ? 1E9 : 1.0 * dx / dy);
        }

        std::sort(slope.begin(), slope.end());

        int cnt = 1;
        for (int j = 1; j < i; j++) {
            if (slope[j] != slope[j - 1]) {
                ans += 1LL * cnt * (cnt - 1) / 2;
                cnt = 0;
            }
            cnt++;
        }
        ans += 1LL * cnt * (cnt - 1) / 2;
    }
    std::cout << ans << "\n";

    return 0;
}