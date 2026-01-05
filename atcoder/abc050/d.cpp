#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N;
    std::cin >> N;

    std::map<int, int> m;
    std::function<i64(i64)> f = [&](i64 x) {
        if (x == 0) {
            return 1;
        }
        if (x == 1) {
            return 2;
        }
        if (m[x]) {
            return m[x];
        }
        if (x % 2 == 1) {
            return m[x] = (2 * f(x / 2) + f(x / 2 - 1)) % P;
        }
        return m[x] = (2 * f(x / 2 - 1) + f(x / 2)) % P;
    };

    std::cout << f(N) << "\n";

    return 0;
}