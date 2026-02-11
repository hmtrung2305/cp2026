#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }

    i64 ans = std::accumulate(D.begin(), D.end(), 0LL);
    std::sort(D.begin(), D.end(), std::greater<int>());
    ans -= std::accumulate(D.begin(), D.begin() + K, 0LL);
    std::cout << ans << "\n";

    return 0;
}