#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ',') {
            std::cout << s[i];
        } else {
            std::cout << " ";
        }
    }
    std::cout << "\n";

    return 0;
}