#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, A, B;
    std::cin >> N >> A >> B;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    i64 ans = 0;
    for (int i = 1; i < N; i++) {
        ans += std::min(1LL * (X[i] - X[i - 1]) * A, 1LL * B);
    }
    std::cout << ans << "\n";

    return 0;
}