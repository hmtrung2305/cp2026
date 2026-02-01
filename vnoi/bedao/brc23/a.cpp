#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    i64 ans = 0;
    int t = 0;
    for (int i = 0; i < N; i++) {
        char c;
        int x;
        std::cin >> c >> x;

        if (c == 'L') {
            ans += x / 100 + (t == 0 ? 0 : t <= x % 100);
            t = (t - x + 100 * x) % 100;
        } else {
            ans += x / 100 + (t == 0 ? 0 : 100 - t <= x % 100);
            t = (t + x) % 100;
        }
    }
    std::cout << ans << "\n";

    return 0;
}