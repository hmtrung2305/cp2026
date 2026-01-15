#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    std::cout << std::max(A * B, C * D) << "\n";

    return 0;
}