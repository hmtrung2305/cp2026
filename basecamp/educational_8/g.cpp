#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int k;
    std::cin >> k;

    if (k == 1) {
        std::cout << *std::max_element(a.begin(), a.end()) << "\n";
        return 0;
    }

    auto check = [&](int x) {
        auto b = a;
        for (int i = 0; i < n; i++) {
            b[i] = std::max(0, b[i] - x);
        }
        i64 cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (b[i] + k - 2) / (k - 1);
        }
        return cnt <= x;
    };

    int lo = 1, hi = 1E9;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    std::cout << lo << "\n";

    return 0;
}