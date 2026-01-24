#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    std::vector<int> ans;
    for (int k = 2; k <= n; k++) {
        if (n % k != 0) {
            continue;
        }
        std::vector<int> mx(k);
        for (int i = 0; i < n; i++) {
            mx[k * i / n] = std::max(mx[k * i / n], d[i]);
        }
        bool ok = 1;
        for (int i = n / k; i < n; i++) {
            if (d[i] < mx[k * i / n - 1]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans.push_back(k);
        }
    }

    if (ans.size() > 0) {
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i] << "\n";
        }
    } else {
        std::cout << -1 << "\n";
    }

    return 0;
}