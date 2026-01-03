#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> x(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
    }

    int L;
    std::cin >> L;

    std::vector<std::vector<int>> dp(17, std::vector<int>(N));
    for (int i = 0, j = 0; i < N; i++) {
        while (x[i] - x[j] > L) {
            j++;
        }
        dp[0][i] = j;
    }
    for (int k = 1; k < 17; k++) {
        for (int i = 0; i < N; i++) {
            dp[k][i] = dp[k - 1][dp[k - 1][i]];
        }
    }

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;

        if (a == b) {
            std::cout << 0 << "\n";
            continue;
        }

        if (a > b) {
            std::swap(a, b);
        }

        int ans = 1;
        for (int k = 16; k >= 0; k--) {
            if (dp[k][b] > a) {
                ans += 1 << k;
                b = dp[k][b];
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}