#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        double b;
        std::cin >> a >> b;
        if (b < 50) {
            ans += a;
        }
    }
    std::cout << ans << "\n";

    return 0;
}