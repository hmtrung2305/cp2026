#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;

    std::vector<std::string> t{"dream", "dreamer", "erase", "eraser"};
    std::vector<int> f(S.size() + 1);
    f[0] = 1;
    for (int i = 1; i <= S.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (i >= t[j].size() && S.substr (i - t[j].size(), t[j].size()) == t[j]) {
                f[i] |= f[i - t[j].size()];
            }
        }
    }
    std::cout << (f[S.size()] ? "YES" : "NO") << "\n";

    return 0;
}