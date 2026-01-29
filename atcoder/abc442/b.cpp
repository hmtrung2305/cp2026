#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Q;
    std::cin >> Q;

    int x = 0, y = 0;
    for (int i = 0; i < Q; i++) {
        int A;
        std::cin >> A;

        if (A == 1) {
            x++;
        } else if (A == 2) {
            if (x) {
                x--;
            }
        } else {
            y ^= 1;
        }

        std::cout << (y && x > 2 ? "Yes" : "No") << "\n";
    }

    return 0;
}