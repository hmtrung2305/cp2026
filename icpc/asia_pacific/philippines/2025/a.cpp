#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    if (s.size() & 1) {
        std::cout << s[s.size() / 2] << "\n";
    } else {
        std::cout << ":)\n";
    }

    return 0;
}