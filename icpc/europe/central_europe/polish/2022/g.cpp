#include <bits/stdc++.h>

constexpr long double esp = 1E-18;

void solve() {
    int n;
    long double k;
    std::cin >> n >> k;

    std::vector<long double> p(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i] >> v[i];
    }

    std::vector<std::array<long double, 2>> pos, neg;
    for (int i = 0; i < n; i++) {
        if (p[i] > 0) {
            pos.push_back({p[i], v[i]});
        } else {
            neg.push_back({p[i], v[i]});
        }
    }

    auto check = [&](long double t) {
        long double mn = 2E19;
        long double mx = -2E19;
        for (auto [x, y] : pos) {
            mn = std::min(mn, x - (long double)t * y);
        }
        for (auto [x, y] : neg) {
            mx = std::max(mx, x + (long double)t * y);
        }
        return mn <= mx;
    };

    long double lo = 0;
    long double hi = 1E12;
    while (hi - lo > std::max((long double)1.0, lo) * esp) {
        long double x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x;
        }
    }

    long double ans = k * lo;
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
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