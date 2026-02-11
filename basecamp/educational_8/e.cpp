#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    i64 x = 0;
    for (int l = 0, r = 0; r < n; r++) {
        x += a[r];
        while (x > m) {
            x -= a[l];
            l++;
        }
        ans = std::max(1LL * ans, x);
    }
    std::cout << ans << "\n";

    return 0;
}