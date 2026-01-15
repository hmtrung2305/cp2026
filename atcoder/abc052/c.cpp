#include <bits/stdc++.h>

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> cnt(N + 1);
    for (int i = 2; i <= N; i++) {
        int x = i;
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                cnt[j]++;
                x /= j;
            }
        }
        if (x > 1) {
            cnt[x]++;
        }
    }

    int ans = 1;
    for (int i = 2; i <= N; i++) {
        ans = 1LL * ans * (cnt[i] + 1) % P;
    }
    std::cout << ans << "\n";

    return 0;
}