#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    int ans = 0;
    int x = 0;
    for (int i = 0; i < N; i++) {
        char c;
        std::cin >> c;
        if (c == 'I') {
            x++;
        } else {
            x--;
        }
        ans = std::max(ans, x);
    }
    std::cout << ans << "\n";

    return 0;
}