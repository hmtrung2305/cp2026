#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M, K;
    std::cin >> M >> K;

    std::vector<std::vector<int>> a(M, std::vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> a[i][j];
        }
    } 

    if ((M + 1) / 2 <= K) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::vector<std::vector<int>> b(2 * M, std::vector<int>(2 * M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            b[i + j][i - j + M] = a[i][j];
        }
    }

    std::vector<std::vector<i64>> s(2 * M, std::vector<i64>(2 * M));
    for (int i = 0; i < 2 * M; i++) {
        for (int j = 0; j < 2 * M; j++) {
            s[i][j] = b[i][j];
            if (i) {
                s[i][j] += s[i - 1][j];
            }
            if (j) {
                s[i][j] += s[i][j - 1];
            }
            if (i && j) {
                s[i][j] -= s[i - 1][j - 1];
            }
        }
    }

    int x = -1, y = -1;
    i64 ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (i < K || i >= M - K || j < K || j >= M - K) {
                continue;
            }

            // std::cerr << i << " " << j << "\n";

            int x1 = i + j - K;
            int x2 = i + j + K;
            int y1 = i - j + M - K;
            int y2 = i - j + M + K;

            i64 sum = s[x2][y2];
            if (x1) {
                sum -= s[x1 - 1][y2];
            }
            if (y1) {
                sum -= s[x2][y1 - 1];
            }
            if (x1 && y1) {
                sum += s[x1 - 1][y1 - 1];
            }

            if (ans < sum) {
                ans = sum;
                x = i;
                y = j;
            }
        }
    }

    std::cout << x + 1 << " " << y + 1 << "\n" << ans << "\n";

    return 0;
}