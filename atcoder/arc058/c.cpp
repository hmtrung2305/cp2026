#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> bad(10);
    for (int i = 0; i < K; i++) {
        int D;
        std::cin >> D;
        bad[D] = 1;
    }

    auto check = [&](int x) {
        std::string s = std::to_string(x);
        for (char c : s) {
            if (bad[c - '0']) {
                return false;
            }
        }
        return true;
    };

    for (int x = N; ; x++) {
        if (check(x)) {
            std::cout << x << "\n";
            return 0;
        }
    }

    return 0;
}