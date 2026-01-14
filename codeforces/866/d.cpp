#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    i64 ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> h;
    for (int i = 0; i < N; i++) {
        h.push(p[i]);
        if (h.top() < p[i]) {
            ans += p[i] - h.top();
            h.pop();
            h.push(p[i]);
        }
    }
    std::cout << ans << "\n";

    return 0;
}