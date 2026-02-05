#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 X;
    std::cin >> X;

    i64 c = 4 * X - 1;

    std::vector<i64> ans;

    auto add = [&](i64 d) {
        ans.push_back((d - c / d - 2) / 4);
    };

    for (i64 d = 1; d * d <= std::abs(c); d += 2) {
        if (c % d != 0) {
            continue;
        }

        add(d);
        add(-d);
        add(c / d);
        add(-c / d);
    }

    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}