#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 A, B, ca, cb, fa;
    std::cin >> A >> B >> ca >> cb >> fa;

    A += B / cb * ca;
    B %= cb;

    if (A >= fa) {
        std::cout << 0 << "\n";
        return;
    }

    i64 k = (fa - A + ca - 1) / ca;
    i64 ans = std::max(0LL, (k - 1) * (cb - ca)) + fa - A + cb - B - 1;

    std::cout << ans << "\n";
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