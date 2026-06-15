#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> h(N), w(N);
    for (int i = 0; i < N; i++) {
        std::cin >> h[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> w[i];
    }

    std::vector<i64> pre(N + 1);
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] + w[i];
    }

    std::vector<int> l(N), r(N);

    std::vector<int> stk;
    for (int i = 0; i < N; i++) {
        l[i] = i - 1;
        while (!stk.empty() && h[i] < h[stk.back()]) {
            l[i] = l[stk.back()];
            stk.pop_back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for (int i = N - 1; i >= 0; i--) {
        r[i] = i + 1;
        while (!stk.empty() && h[i] <= h[stk.back()]) {
            r[i] = r[stk.back()];
            stk.pop_back();
        }
        stk.push_back(i);
    }

    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = (pre[r[i]] - pre[l[i] + 1]) % P;
        int mx = std::max(l[i] >= 0 ? h[l[i]] : 0, r[i] < N ? h[r[i]] : 0);
        ans = (ans + (1LL * cnt * (cnt + 1) / 2 % P) * (1LL * (h[i] - mx) * (h[i] + mx + 1) / 2 % P)) % P;
    }
    std::cout << ans << "\n";

    return 0;
}