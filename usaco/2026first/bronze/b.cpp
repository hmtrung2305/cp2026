#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    if (N & 1) {
        std::cout << "-1\n";
        return;
    }

    N *= 3;
    if (S.substr(0, N / 2) == S.substr(N / 2)) {
        std::cout << 1 << "\n";
        for (int i = 0; i < N; i++) {
            std::cout << 1 << " \n"[i == N - 1];
        }
        return;
    }

    std::vector<int> ans(N);

    for (int i = 0; i < N / 2; i += 3) {
        bool ok = 0;
        for (int a = 0; a < 3; a++) {
            for (int b = a + 1; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    for (int d = c + 1; d < 3; d++) {
                        if (S[i + a] == S[i + c + N / 2] && S[i + b] == S[i + d + N / 2]) {
                            ans[i + a] = 1;
                            ans[i + c + N / 2] = 1;
                            ans[i + b] = 1;
                            ans[i + d + N / 2] = 1;
                            ans[i + (3 - a - b)] = 2;
                            ans[i + (3 - c - d) + N / 2] = 2;
                        }
                    }
                }
            }
        }
    }

    std::cout << 2 << "\n";
    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, k;
    std::cin >> t >> k;

    while (t--) {
        solve();
    }

    return 0;
}