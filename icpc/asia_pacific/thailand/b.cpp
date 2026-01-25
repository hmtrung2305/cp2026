#include <bits/stdc++.h>

void solve() {
    int N, M;
    std::cin >> N >> M;

    if (N == 1) {
        std::cout << 1 << "\n";
    } else if (N == 2) {
        if (M % 2 == 0) {
            std::cout << "1 2\n";
        } else {
            std::cout << "2 1\n";
        }
    } else if (M < N) {
        for (int i = N; i > N - M; i--) {
            std::cout << i << " ";
        }
        for (int i = 1; i <= N - M; i++) {
            std::cout << i << " \n"[i == N - M];
        }
    } else {
        for (int i = N; i > 0; i--) {
            std::cout << i << " \n"[i == 1];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}