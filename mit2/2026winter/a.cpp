#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == 0 || j == N - 1) {
                std::cout << "#";
            } else if ((j <= N / 2 && i == j) || (j > N / 2 && i + j == N - 1)) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
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