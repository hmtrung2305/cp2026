#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    i64 ans = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> u, d;
    for (int i = 0; i < n; i++) {
        int p;
        char c;
        std::cin >> p >> c;
        ans += p;
        if (p == 0) {
            d.push(m);
        } else if (p == m) {
            u.push(m);
        } else if (c == 'U') {
            d.push(m - p);
        } else {
            u.push(p);
        }
    }

    i64 cur = ans;
    for (int t = 1; t < 2 * m; t++) {
        cur += d.size() - u.size();
        ans = std::max(ans, cur);

        while (!u.empty() && t == u.top()) {
            u.pop();
            d.push(m + t);
        }
        while (!d.empty() && t == d.top()) {
            d.pop();
            u.push(m + t);
        }
    }

    std::cout << ans << "\n";

    return 0;
}