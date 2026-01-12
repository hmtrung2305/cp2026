#include <bits/stdc++.h>
using namespace std;
#define f(i, l, r) for (int i = (l), _##i = (r); i < _##i; i++)
#define fr(i, l, r) for (int i = (r) - 1, _##i = (l); i >= _##i; i--)
using LL = long long;
constexpr LL MOD = 998244353;
LL power(LL a, LL b) {
    LL res = 1; a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return res;
}
struct Fenwick {
    vector<int> d;
    Fenwick(int n) : d(n + 1) {}
    void add(int i) { for (++i; i < (int)d.size(); i += i & -i) d[i]++; }
    int ask(int i) { int s = 0; for (; i > 0; i -= i & -i) s += d[i]; return s; }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> p(n);
    f(i, 0, n) cin >> p[i];
    vector<LL> L(n), R(n);
    { Fenwick fen(n); f(i, 0, n) { L[i] = fen.ask(p[i] - 1); fen.add(p[i] - 1); } }
    { Fenwick fen(n); fr(i, 0, n) { R[i] = fen.ask(p[i] - 1); fen.add(p[i] - 1); } }
    LL ans = 0;
    f(i, 0, n) ans = (ans + L[i] * R[i]) % MOD;
    LL inv2 = power(2, MOD - 2);
    vector<LL> pw2(n + 1), ipw2(n + 1);
    pw2[0] = ipw2[0] = 1;
    f(i, 1, n + 1) pw2[i] = pw2[i-1] * 2 % MOD, ipw2[i] = ipw2[i-1] * inv2 % MOD;
    LL pre = 0;
    f(c, 1, n) {
        pre = (pre + L[c-1] * ipw2[c-1]) % MOD;
        ans = (ans + R[c] * pw2[c-1] % MOD * pre) % MOD;
    }
    cout << ans << '\n';
}
