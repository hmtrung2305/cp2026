#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    std::cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        if (l <= s && s <= r) {
            s++;
        }
    }
    std::cout << s << "\n";

    return 0;
}