#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> T(N);
    for (int i = 0; i < N; i++) {
        std::cin >> T[i];
    }

    int ans = std::accumulate(T.begin(), T.end(), 0);

    int M;
    std::cin >> M;

    for (int i = 0; i < M; i++) {
        int P, X;
        std::cin >> P >> X;
        P--;

        std::cout << ans - T[P] + X << "\n";
    }

    return 0;
}