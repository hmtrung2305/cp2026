#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B;
    char op;
    std::cin >> A >> op >> B;

    std::cout << (op == '+' ? A + B : A - B) << "\n";

    return 0;
}