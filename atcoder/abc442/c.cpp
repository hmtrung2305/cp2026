#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> c(N, N - 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        std::cin >> A >> B;
        A--;
        B--;
        c[A]--;
        c[B]--;
    }

    for (int i = 0; i < N; i++) {
        i64 ans = 1LL * c[i] * (c[i] - 1) * (c[i] - 2) / 6;
        std::cout << ans << " \n"[i == N - 1];
    }

    return 0;
}