#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> L(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        std::cin >> L[i];
    }

    std::sort(L.begin(), L.end());

    int ans = 0;
    for (int i = 0; i < 2 * N; i += 2) {
        ans += L[i];
    }
    std::cout << ans << "\n";

    return 0;
}