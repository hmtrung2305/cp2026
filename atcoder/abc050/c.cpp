#include <bits/stdc++.h>

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> c(N);
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        c[A]++;
    }

    std::vector<int> b(N);
    for (int i = 0; i < N; i++) {
        b[std::abs(i - (N - i - 1))]++;
    }

    for (int i = 0; i < N; i++) {
        if (c[i] != b[i]) {
            std::cout << 0 << "\n";
            return 0;
        }
    }

    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (c[i] == 2) {
            ans = ans * 2 % P;
        }
    }
    std::cout << ans << "\n";

    return 0;
}