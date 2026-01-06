#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K, S;
    std::cin >> K >> S;

    int ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            if (x + y <= S && x + y + K >= S) {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}