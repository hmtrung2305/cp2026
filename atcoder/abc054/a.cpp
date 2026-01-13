#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B;
    std::cin >> A >> B;

    A = (A - 2 + 13) % 13;
    B = (B - 2 + 13) % 13;

    if (A > B) {
        std::cout << "Alice\n";
    } else if (A < B) {
        std::cout << "Bob\n";
    } else {
        std::cout << "Draw\n";
    }

    return 0;
}