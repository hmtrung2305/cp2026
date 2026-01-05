#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<int, int> f;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        int b = 0;
        for (char c : s) {
            b ^= 1 << (c - 'a');
        }
        f[b]++;
    }

    i64 ans = 0;
    for (auto [b, cnt] : f) {
        ans += 1LL * cnt * (cnt - 1) / 2;
        for (int i = 0; i < 26; i++) {
            int nb = b ^ (1 << i);
            if (b < nb && f.count(nb)) {
                ans += 1LL * cnt * f[nb];
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}