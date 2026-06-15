#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;

    int ans = 0;
    for (int i = 0; i + 3 < (int) s.size(); ++i) {
        if (s[i] == 'a' && s[i + 1] == 'n' && s[i + 2] == 'i' && s[i + 3] == 'a') {
            ++ans;
            s[i + 3] = 'w';
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    // }

    return 0;
}