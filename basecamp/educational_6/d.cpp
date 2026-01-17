#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if (cur + s.size() <= k) {
            cur += s.size();
            std::cout << s << " \n"[i == n - 1];
        } else {
            cur = s.size();
            std::cout << "\n" << s << " \n"[i == n - 1];
        }
    }

    return 0;
}