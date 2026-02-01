#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> a(N, std::vector<int>(N));
    std::vector<std::vector<int>> pre(N, std::vector<int>(N));

    int Q;
    std::cin >> Q;

    int ans = 0;
    for (int i = 0; i < Q; i++) {
        int r, c, v;
        std::cin >> r >> c >> v;
        r--;
        c--;

        int add = v - a[r][c];
        a[r][c] = v;
        for (int x = std::max(0, r - K + 1); x <= r && x <= N - K; x++) {
            for (int y = std::max(0, c - K + 1); y <= c && y <= N - K; y++) {
                pre[x][y] += add;
                ans = std::max(ans, pre[x][y]);
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}