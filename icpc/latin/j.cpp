#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int W, H;
    std::cin >> W >> H;

    int N;
    std::cin >> N;

    std::vector<std::pair<i64, int>> d;

    auto val = [&](int x, int y) {
        if (x == 0) {
            return 1LL * y;
        } else if (y == H) {
            return 1LL * H + x;
        } else if (x == W) {
            return 1LL * H + W + H - y;
        } else if (y == 0) {
            return 1LL * H + W + H + W - x;
        }
        return -1LL;
    };

    for (int i = 1; i <= N; i++) {
        int X1, Y1, X2, Y2;
        std::cin >> X1 >> Y1 >> X2 >> Y2;

        i64 a = val(X1, Y1);
        i64 b = val(X2, Y2);

        if (a >= 0 && b >= 0) {
            if (a > b) {
                std::swap(a, b);
            }
            d.push_back({a, i});
            d.push_back({b, -i});
        }
    }


    std::sort(d.begin(), d.end());

    std::vector<int> stk;
    for (auto [_, i] : d) {
        // std::cerr << _ << " " << i << "\n";
        if (i < 0) {
            if (stk.back() != -i) {
                std::cout << "N\n";
                return 0;
            }
            stk.pop_back();
        } else {
            stk.push_back(i);
        }
    }
    std::cout << "Y\n";

    return 0;
}