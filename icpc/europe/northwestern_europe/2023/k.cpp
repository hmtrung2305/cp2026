#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<long long> pow2 = {1};
    while (pow2.back() * 2 <= (long long) 1E18) {
        pow2.push_back(pow2.back() * 2);
    }

    std::vector<long long> pref(pow2.size());
    pref[0] = 1;
    for (int i = 1; i < (int) pow2.size(); ++i) {
        pref[i] = pref[i - 1] + pow2[i];
    }

    auto solve = [&]() -> void {
        long long x;
        std::cin >> x;

        int ans = 0;
        while (x > 0) {
            long long v = *std::prev(std::upper_bound(pref.begin(), pref.end(), x));
            x -= v;
            ++ans;
        }
        std::cout << ans - 1 << '\n';
    };

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}