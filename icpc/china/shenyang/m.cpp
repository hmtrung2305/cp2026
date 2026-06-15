#include <bits/stdc++.h>

constexpr int P = 1E9 + 7;
constexpr int N = 1E6;

std::vector<int> p;

int power(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = 1LL * res * a % P;
        }
        a = 1LL * a * a % P;
        n >>= 1;
    }
    return res;
}

void solve() {
    std::string s, t;
    int k;
    std::cin >> s >> t >> k;

    int ls = s.size();
    int lt = t.size();
    std::reverse(s.begin(), s.end());
    std::reverse(t.begin(), t.end());

    int n = (std::max(ls, lt) + 1) / 2;
    std::vector<int> x(n);
    for (int i = 0; i < ls; i++) {
        x[i >> 1] ^= (s[i] - '0') << (i & 1);
    }
    for (int i = 0; i < lt; i++) {
        x[i >> 1] ^= (t[i] - '0') << (i & 1);
    }

    // for (int z : x) {
    //     std::cout << z;
    // }
    // std::cout << "\n";

    bool zero = true;
    for (int i = 0; i < n; i++) {
        zero &= !x[i];
    }

    int ans = 0;
    if (zero) {
        ans = (((1LL * power(4, k) - 1 + P) % P * power(3, P - 2) % P) - 1 + P) % P;
    } else {
        int sum = 0;
        
        for (int i = ) {

        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    p.resize(N + 1);
    p[0] = 1;
    for (int i = 1; i <= N; i++) {
        p[i] = 4 * p[i - 1] + 1;
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}