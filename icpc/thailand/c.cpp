#include <bits/stdc++.h>

const int N = 700;
const int M = 250000;
std::bitset<2 * M> b[N + 1];

void solve() {
    int X;
    std::cin >> X;

    int n = 1;
    while (!b[n][M + X]) {
        n++;
    }

    std::cout << n << "\n";
    std::function<void(int, int)> dfs = [&](int i, int val) {
        if (i == 1) {
            std::cout << 1;
            return;
        }
        if (b[i - 1][M + val - i]) {
            dfs(i - 1, val - i);
            std::cout << "+" << i;
        } else if (b[i - 1][M + val + i]) {
            dfs(i - 1, val + i);
            std::cout << "-" << i;
        }
    };
    dfs(n, X);
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    b[1][M + 1] = 1;
    for (int i = 2; i <= N; i++) {
        b[i] = (b[i - 1] << i) | (b[i - 1] >> i);
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}