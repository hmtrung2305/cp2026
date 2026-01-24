#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int ans = 0;
    i64 r = 0;
    for (int b = 1; b <= n; b *= 10) {
        for (int i = b; i < 10 * b && i <= n; i++) {
            r = (r * 10 * b + i) % k;
            ans += r == 0;
        }
    }
    std::cout << ans << "\n";

    return 0;
}