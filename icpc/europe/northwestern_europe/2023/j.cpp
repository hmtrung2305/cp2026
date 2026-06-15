#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    auto check_min = [&](int x) {
        for (int i = 0; i < x; i++) {
            if (a[i] >= b[n - x + i]) {
                return false;
            }
        }
        return true;
    };
    auto check_max = [&](int x) {
        for (int i = 0; i < x; i++) {
            if (a[n - x + i] <= b[i]) {
                return false;
            }
        }
        return true;
    };

    int lo = 0, hi = n;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check_min(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    int mn = n - lo;

    lo = 0, hi = n;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check_max(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    int mx = lo;

    // std::cerr << mn << " " << mx << "\n";
    std::cout << mx - mn + 1 << "\n";
    for (int i = mn; i <= mx; i++) {
        std::cout << i << " \n"[i == mx];
    }

    return 0;
}