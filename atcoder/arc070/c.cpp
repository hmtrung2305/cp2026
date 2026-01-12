#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int X;
    std::cin >> X;

    int ans = 1;
    while (ans * (ans + 1) / 2 < X) {
        ans++;
    }
    std::cout << ans << "\n";

    return 0;
}