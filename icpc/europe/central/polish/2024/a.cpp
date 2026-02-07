#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::string e[26];
    for (int i = 0; i < n; i++) {
        e[s[i][0] - 'A'] = s[i];
    }

    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (auto c : s[i]) {
            if (e[c - 'A'].empty()) {
                ok = false;
            }
        }
        if (ok) {
            std::cout << s[i].size() << "\n";
            for (auto c : s[i]) {
                std::cout << e[c - 'A'] << " ";
            }
            std::cout << "\n";
            return 0;
        }
    }
    std::cout << -1 << "\n";

    return 0;
}