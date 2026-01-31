#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w, k, i, t;
    std::cin >> h >> w >> k >> i >> t;

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            int id = x * w + y;

            if (id == 0) {
                std::cout << "K";
            } else if (id == 1) {
                std::cout << "I";
            } else if (id == 2) {
                std::cout << "T";
            } else if (id < t + 2) {
                std::cout << "T";
            } else if (id < t + k + 1) {
                std::cout << "K";
            } else {
                std::cout << "I";
            }
        }
        std::cout << "\n";
    }

    return 0;
}