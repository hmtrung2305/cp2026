#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int s = std::accumulate(a.begin(), a.end(), 0);
    int ans = s;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            ans = std::max(ans, s - 4 * a[i]);
        }
    }
    std::cout << ans << "\n";

    return 0;
}