#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, T;
    std::cin >> N >> T;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;

    int x = 0;
    for (int i = 0; i < N; i++) {
        if (x < A[i]) {
            ans += A[i] - x;
            x = A[i] + 100;
        }
    }
    if (x < T) {
        ans += T - x;
    }

    std::cout << ans << "\n";

    return 0;
}