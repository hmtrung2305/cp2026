#include <bits/stdc++.h>

int digitsum(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (digitsum(i) == K) {
            ans++;
        }
    }
    std::cout << ans << "\n";

    return 0;
}