#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += n / i;
    }
    std::cout << ans << "\n";

    return 0;
}