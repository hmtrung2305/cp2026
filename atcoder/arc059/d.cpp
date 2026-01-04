#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            std::cout << i + 1 << " " << i + 2 << "\n";
            return 0;
        }
        if (i + 2 < s.size() && s[i] == s[i + 2]) {
            std::cout << i + 1 << " " << i + 3 << "\n";
            return 0;
        }
    }
    std::cout << -1 << " " << -1 << "\n";

    return 0;
}