#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    int sa = std::accumulate(a.begin(), a.end(), 0);
    int sb = std::accumulate(b.begin(), b.end(), 0);

    for (int i = 0; i < n; i++) {
        if (sb - sa + a[i] <= b[i]) {
            std::cout << i + 1 << "\n";
            return 0;
        }
    }
    std::cout << "impossible\n";

    return 0;
}