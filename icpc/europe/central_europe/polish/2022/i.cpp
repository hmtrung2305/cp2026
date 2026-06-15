#include <bits/stdc++.h>

constexpr int inf = 1E9;

void solve() {
    int n, k;
    std::cin >> n >> k;
    k++;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                f[i][j + 1]++;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            f[i][j] += f[i + 1][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            f[i][j + 1] += f[i][j];
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         std::cout << f[i][j] << " \n"[j == n];
    //     }
    // }

    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, inf));
    std::vector<std::vector<int>> cut(k + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[1][i] = f[0][i];
        cut[1][i] = 0;
    }

    for (int c = 2; c <= k; c++) {
        for (int r = n; r >= 0; r--) {
            int x = cut[c - 1][r];
            int y = (r == n ? n : cut[c][r + 1]);
            for (int l = x; l <= y; l++) {
                if (dp[c][r] > dp[c - 1][l] + f[l][r]) {
                    dp[c][r] = dp[c - 1][l] + f[l][r];
                    cut[c][r] = l;
                }
            }
        }
    }

    std::cout << dp[k][n] << "\n";
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