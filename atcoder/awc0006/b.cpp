#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    i64 T;
    std::cin >> N >> K >> T;

    std::vector<int> D(N), R(N);
    for (int i = 0; i < N; i++) {
        std::cin >> D[i] >> R[i];
    }

    i64 s = 0;
    for (int i = 0; i < N; i++) {
        if (R[i] >= K * D[i]) {
            s += R[i];
        }
    }
    std::cout << (s >= T ? "Yes" : "No") << "\n";

    return 0;
}