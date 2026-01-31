#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    int ans = 0;
    int s = N;
    while (s < K) {
        ans++;
        s += N + ans;
        if (s >= K) {
            std::cout << ans << "\n";
            return 0;
        }
    }
    std::cout << 0 << "\n";

    return 0;
}