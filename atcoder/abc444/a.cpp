#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string N;
    std::cin >> N;

    std::cout << (N[0] == N[1] && N[1] == N[2] ? "Yes" : "No") << "\n";

    return 0;
}