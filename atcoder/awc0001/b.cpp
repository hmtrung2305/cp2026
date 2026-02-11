#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L, R;
    std::cin >> N >> L >> R;

    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    int ans = -1;
    int mx = -1;
    for (int i = 0; i < N; i++) {
        if (P[i] >= L && P[i] <= R && mx < P[i]) {
            mx = P[i];
            ans = i + 1;
        }
    }
    std::cout << ans << "\n";

    return 0;
}