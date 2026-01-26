#include <bits/stdc++.h>

constexpr double esp = 1E-3;
constexpr double inf = 1E12;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i] >> s[i];
    }

    double m;
    std::cin >> m;

    std::vector<double> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * m;
    }

    auto check = [&](double lim) {
        std::vector<std::vector<double>> dp(1 << n, std::vector<double>(n, inf));
        dp[0][0] = 0;
        
        for (int mask = 1; mask < (1 << n); mask++) {
            int nb = __builtin_popcount(mask);
            if (nb == 1) {
                int i = __builtin_ctz(mask);
                double t = sqrt(x[i] * x[i] + y[i] * y[i]) / lim;
                if (t <= s[i]) {
                    dp[mask][i] = t;
                }
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    int nmask = mask ^ (1 << i);
                    for (int j = 0; j < n; j++) {
                        if (nmask >> j & 1) {
                            double nlim = lim * p[nb - 1];
                            double t = dp[nmask][j] + sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) / nlim;
                            if (dp[nmask][j] != inf && t <= s[i]) {
                                dp[mask][i] = std::min(dp[mask][i], t);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] != inf) {
                return true;
            }
        }
        return false;
    };
    
    double lo = 0, hi = 1E9;
    while (hi - lo > esp) {
        double x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x;
        }
    }
    std::cout << std::fixed << std::setprecision(3) << lo << "\n";

    return 0;
}