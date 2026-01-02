#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    int ans = 1E9;
    for (int x = -100; x <= 100; x++) {
        int res = 0;
        for (int i = 0; i < N; i++) {
            res += (a[i] - x) * (a[i] - x);
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << "\n";

    return 0;
}