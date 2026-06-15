#include <bits/stdc++.h>

int main() {
    freopen("BA.INP", "r", stdin);
    freopen("BA.OUT", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string B;
    std::cin >> B;

    int s = 0;
    for (int i = 0; i < B.size(); i++) {
        if (B[i] == '3') {
            std::cout << "BA\n";
            return 0;
        }
        s += (B[i] - '0');
    }
    std::cout << (s % 3 == 0 ? "BA" : "NOMOREBA") << "\n";

    return 0;
}