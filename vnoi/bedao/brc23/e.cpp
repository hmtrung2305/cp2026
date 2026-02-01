#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> e(N + 1);
    for (int i = 0; i < N / 2; i++) {
        int x, y;
        std::cin >> x >> y;
        e[x] = y;
        e[y] = x;
    }

    std::vector<std::pair<int, int>> p;
    for (int i = 1; i <= N; i++) {
        p.push_back({A[i], i});
    }
    std::sort(p.begin(), p.end());

    std::vector<int> idx(N + 1), val(N + 1);
    for (int i = 0; i < N; i++) {
        idx[i + 1] = p[i].first;
        val[i + 1] = p[i].second;
        // std::cerr << idx[i + 1] << " " << val[i + 1] << "\n";
    }

    std::vector<std::vector<i64>> dp(N + 2, std::vector<i64>(N + 2, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            dp[i][j] = inf;
        }
    }
    for (int len = 2; len <= N; len += 2) {
        for (int l = 1; l + len - 1 <= N; l++) {
            int r = l + len - 1;
            for (int m = l + 1; m <= r; m += 2) {
                if (e[idx[l]] == idx[m]) {
                    continue;
                }

                i64 lhs = dp[l + 1][m - 1];
                i64 rhs = dp[m + 1][r];
                if (lhs >= inf || rhs >= inf) {
                    continue;
                }

                dp[l][r] = std::min(dp[l][r], (val[m] - val[l]) + lhs + rhs);
                std::cerr << m << " " << l << " " << val[m] << " " << val[l] << "\n";
            }
        }
    }

    std::cout << dp[1][N] << "\n";

    return 0;
}