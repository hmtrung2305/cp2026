#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string n;
    std::cin >> n;

    for (int i = 0; i < n.size(); i++) {
        if (n[i] - '0' != i + 1) {
            std::cout << "-1\n";
            return 0;
        }
    }
    std::cout << n.size() << "\n";

    return 0;
}