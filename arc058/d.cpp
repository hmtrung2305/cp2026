#include <bits/stdc++.h>

constexpr int P = 1E9 + 7;

int power(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = 1LL * res * a % P;
        }
        a = 1LL * a * a % P;
        n /= 2;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, A, B;
    std::cin >> H >> W >> A >> B;

    std::vector<int> fac(H + W + 1), invfac(H + W + 1);
    fac[0] = 1;
    for (int i = 1; i <= H + W; i++) {
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
    invfac[H + W] = power(fac[H + W], P - 2);
    for (int i = H + W; i > 0; i--) {
        invfac[i - 1] = 1LL * invfac[i] * i % P;
    }

    auto comb = [&](int x, int y) {
        return 1LL * fac[y] * invfac[y - x] % P * invfac[x] % P;
    };

    int ans = 0;
    for (int i = 0; i < H - A; i++) {
        int rem = comb(H - i - 1, W - B - 1 + H - i - 1);
        ans = (ans + 1LL * comb(i, B - 1 + i) * rem % P) % P;
    }
    std::cout << ans << "\n";

    return 0;
}