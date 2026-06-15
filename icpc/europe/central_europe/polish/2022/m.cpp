#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int m;
    std::cin >> m;

    std::vector<int> s(m);
    std::vector<bool> c(n, false);
    for (int i = 0; i < m; i++) {
        std::cin >> s[i];
        s[i]--;
        c[s[i]] = true;
    }

    std::string ans(k, 'N');
    for (int i = k - 1; i >= 0; i--) {
        if (!c[b[i]]) {
            continue;
        }
        if (!c[a[i]]) {
            c[b[i]] = false;
            ans[i] = 'T';
        }
    }

    bool ok = true;
    for (int i = 0; i < m; i++) {
        ok &= !c[s[i]];
    }

    if (ok) {
        std::cout << "TAK\n" << ans << "\n";
    } else {
        std::cout << "NIE\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}