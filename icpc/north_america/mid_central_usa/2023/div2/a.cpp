#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int ans = 0;
    int cnt[3] = {};
    for (auto c : s) {
        cnt[c - 'A']++;
        
        int mn = std::min({cnt[0], cnt[1], cnt[2]});
        cnt[0] -= mn;
        cnt[1] -= mn;
        cnt[2] -= mn;

        ans = std::max({ans, cnt[0], cnt[1], cnt[2]});
    }
    std::cout << ans << "\n";

    return 0;
}