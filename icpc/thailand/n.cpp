#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, A, B;
    std::cin >> N >> A >> B;

    int pa = A + 1;
    int pb = N - B;
    std::cout << std::abs(pa - pb) - 1 << "\n";

    return 0;
}