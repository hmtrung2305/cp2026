#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 ans = 0;
    std::priority_queue<int> h;
    h.push(a[0]);
    for (int i = 1; i < n; i++) {
        a[i] -= i;
        h.push(a[i]);
        if (h.top() > a[i]) {
            ans += h.top() - a[i];
            h.pop();
            h.push(a[i]);
        }
    }
    std::cout << ans << "\n";

    return 0;
}