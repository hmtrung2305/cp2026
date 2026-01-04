#include <bits/stdc++.h>

using i64 = long long;

i64 f(i64 b, i64 n) {
    i64 res = 0;
    while (n) {
        res += n % b;
        n /= b;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, s;
    std::cin >> n >> s;

    if (s > n) {
        std::cout << -1 << "\n";
        return 0;
    }

    if (s == n) {
        std::cout << n + 1 << "\n";
        return 0;
    }

    for (i64 i = 2; i * i <= n; i++) {
        if (f(i, n) == s) {
            std::cout << i << "\n";
            return 0;
        }
    }

    std::vector<i64> cand;
    for (i64 i = 1; i * i <= n - s; i++) {
        if ((n - s) % i == 0) {
            cand.push_back(i);
        }
    }
    for (i64 b : cand) {
        if (f(b + 1, n) == s) {
            std::cout << b + 1 << "\n";
            return 0;
        }
    }

    std::reverse(cand.begin(), cand.end());
    for (i64 b : cand) {
        if (f((n - s) / b + 1, n) == s) {
            std::cout << (n - s) / b + 1 << "\n";
            return 0;
        }
    }

    std::cout << -1 << "\n";

    return 0;
}