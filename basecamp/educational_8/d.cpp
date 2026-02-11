#include <bits/stdc++.h>

using i64 = long long;

std::vector<std::vector<i64>> binom;
void sieve(int n) {
    binom.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        binom[i].resize(i + 1);
        binom[i][0] = 1;
        for (int j = 1; j < i; j++) {
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
        }
        binom[i][i] = 1;
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::cout << binom[n][m - 1] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(30);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}