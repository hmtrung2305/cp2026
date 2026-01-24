#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::sort(p.begin(), p.end());

    int ans = 0;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && p[j] - p[i] <= d) {
            j++;
        }
        i = j;
        ans ++;
    }
    std::cout << ans << "\n";

    return 0;
}