#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::map<int, bool> m;
    int x = N;
    while (x != 1) {
        if (m[x]) {
            std::cout << "No\n";
            return 0;
        }
        m[x] = 1;
        std::string s = std::to_string(x);
        int y = 0;
        for (char c : s) {
            y += (c - '0') * (c - '0');
        }
        x = y;
    }
    std::cout << "Yes\n";

    return 0;
}