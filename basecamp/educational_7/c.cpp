#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<std::array<int, 3>> s(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        s[i][x]++;
    }

    for (int i = 1; i < n; i++) {
        s[i][0] += s[i - 1][0];
        s[i][1] += s[i - 1][1];
        s[i][2] += s[i - 1][2];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        r--;
        for (int j = 0; j < 3; j++) {
            std::cout << s[r][j] - (l == 0 ? 0 : s[l - 1][j]) << " \n"[j == 2];
        }
    }

    return 0;
}