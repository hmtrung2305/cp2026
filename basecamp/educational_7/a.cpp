#include <bits/stdc++.h>

using real = long double;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char x;
    int a, b, c, d;
    std::cin >> a >> x >> b;
    std::cin >> c >> x >> d;

    real log1 = b * std::logl(a);
    real log2 = d * std::logl(c);

    if (log1 > log2) {
        std::cout << a << "^" << b << "\n";
    } else {
        std::cout << c << "^" << d << "\n";
    }

    return 0;
}