#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> H(N);
    for (int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    std::multiset<int> s;
    for (int i = 0; i < K; i++) {
        s.insert(H[i]);
    }

    int ans = 0;
    for (int i = 0; i <= N - K; i++) {
        ans = std::max(ans, *std::prev(s.end()) - *s.begin());
        if (i < N - K) {
            s.erase(s.find(H[i]));
            s.insert(H[i + K]);
        }
    }
    std::cout << ans << "\n";

    return 0;
}