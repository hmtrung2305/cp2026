#include <bits/stdc++.h>

using i64 = long long;

int main() {
    freopen("FISH.INP", "r", stdin);
    freopen("FISH.OUT", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](int i, int j) {
            return a[i] < a[j];
        });

    std::vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int mn = a[p[0]];
    int cnt = 0;
    while (cnt < n && a[p[cnt]] == mn) {
        cnt++;
    }

    std::vector<bool> ok(n + 1);
    for (int i = 2; i <= n; i++) {
        ok[i] = (pre[i - 1] > a[p[i - 1]]);
    }
    std::vector<bool> suf(n + 2, 1);
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = suf[i + 1] && ok[i + 1];
    }

    std::vector<int> ans(n + 1, 3);
    for (int i = 1; i <= n; i++) {
        if ((a[p[i - 1]] == mn && cnt > 1) || (!suf[i])) {
            ans[p[i - 1]] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i];
    }
    std::cout << "\n";

    return 0;
}