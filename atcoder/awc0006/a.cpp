#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L, W;
    std::cin >> N >> L >> W;

    std::vector<int> D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L - W <= D[i] && D[i] <= L + W;
    }
    std::cout << ans << "\n";

    return 0;
}