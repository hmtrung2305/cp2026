#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    i64 ans = 0;
    std::priority_queue<int> h;
    for (int i = 0; i < n; i++) {
        h.push(x[i]);
        if (h.top() > x[i]) {
            ans += h.top() - x[i];
            h.pop();
            h.push(x[i]);
        }
    }
    std::cout << ans << "\n";

    return 0;
}