#include <bits/stdc++.h>

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    std::vector<std::vector<int>> f(N + 1, std::vector<int>(11));
    f[0][0] = 1;
    for (int l = 1; l <= N; l++) {
        for (int p = 0; p <= N * 10; p++) {
            for (int x = 1; x <= 10; x++) {
                f[l][p + x] = f[l - 1][] + f[l - 1][];
            }
        }
    }

    return 0;
}