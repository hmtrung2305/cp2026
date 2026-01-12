#include <bits/stdc++.h>

constexpr int MOD = 998244353;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T());
    }

    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int power(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = 1LL * res * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        P[i]--;
    }

    std::vector<int> L(N), R(N);
    {
        Fenwick<int> fen(N);
        for (int i = 0; i < N; i++) {
            L[i] = fen.sum(P[i]);
            fen.add(P[i], 1);
        }
    }
    {
        Fenwick<int> fen(N);
        for (int i = N - 1; i >= 0; i--) {
            R[i] = fen.sum(P[i]);
            fen.add(P[i], 1);
        }
    }

    std::vector<int> pw2(N + 1), ipw2(N + 1);
    {
        pw2[0] = 1;
        for (int i = 1; i <= N; i++) {
            pw2[i] = pw2[i - 1] * 2 % MOD;
        }
        int inv2 = power(2, MOD - 2);
        ipw2[0] = 1;
        for (int i = 1; i <= N; i++) {
            ipw2[i] = 1LL * ipw2[i - 1] * inv2 % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + 1LL * L[i] * R[i] % MOD) % MOD;
    }
    int pre = 0;
    for (int i = 1; i < N; i++) {
        pre = (pre + 1LL * L[i - 1] * ipw2[i - 1] % MOD) % MOD;
        ans = (ans + 1LL * R[i] * pw2[i - 1] % MOD * pre % MOD) % MOD;
        std::cerr << 1LL * pw2[i - 1] * ipw2[i - 1] % MOD << "\n";
    }

    std::cout << ans << "\n";

    return 0;
}