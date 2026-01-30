#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, p;
    std::cin >> n >> p;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    for (int t = 0; t < 35; t++) {
        int i = rng() % n;
        int j = rng() % n;

        int cnt = 0;

        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        if (dy == 0) {
            for (int k = 0; k < n; k++) {
                cnt += y[k] == y[i];
            }
        } else {
            for (int k = 0; k < n; k++) {
                if (1LL * dx * (y[k] - y[i]) == 1LL * dy * (x[k] - x[i])) {
                    cnt++;
                }
            }
        }

        if (cnt * 100 >= p * n) {
            std::cout << "possible\n";
            return;
        }
    }
    std::cout << "impossible\n";
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