#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.size();

    std::vector<std::vector<bool>> pal(n, std::vector<bool>(n));
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            pal[i][i + 1] = 1;
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (s[l] == s[r] && (len == 3 || pal[l + 1][r - 1])) {
                pal[l][r] = 1;
            }
        }
    }

    i64 ans = 0;
    for (int l = 0; l < n; l++) {
        std::vector<bool> dp(n);
        for (int r = l; r < n; r++) {
            bool ok = 0;
            if (pal[l][r]) {
                ok = 1;
            }
            if (!ok) {
                for (int i = l; i < r; i++) {
                    if (dp[i] && pal[i + 1][r]) {
                        ok = 1;
                        break;
                    }
                }
            }
            dp[r] = ok;
            ans += ok;
        }
    }
    std::cout << ans << "\n";

    return 0;
}