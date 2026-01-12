#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> cnt(N + 1);
    for (int x = 1; x * x * 2 <= N; x++) {
        for (int y = x + 1; y * y + x * x <= N; y++) {
            cnt[x * x + y * y]++;
        }
    }

    std::vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 1) {
            ans.push_back(i);
        }
    }

    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}