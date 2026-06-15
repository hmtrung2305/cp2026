#include <bits/stdc++.h>

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
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

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < k; i++) {
        int l;
        std::cin >> l;
        cnt[l]++;
    }

    std::vector<int> pa(n + 1);
    for (int i = 0; i < n; i++) {
        pa[a[i]] = i + 1;
    }
    std::vector<int> hb(n + 1);
    for (int i = 0; i < m; i++) {
        hb[b[i]] = 1;
    }

    for (int i = 0; i < m - 1; i++) {
        if (pa[b[i]] > pa[b[i + 1]]) {
            std::cout << "NO\n";
            return;
        }
    }

    std::set<int> s{0, n + 1};
    Fenwick<int> fen(n + 1);
    for (int i = n; i > 0; i--) {
        if (hb[i]) {
            s.insert(pa[i]);
            continue;
        }

        auto it = s.lower_bound(pa[i]);
        int l = *std::prev(it);
        int r = *it - 1;
        // std::cerr << l << " " << r << "\n";

        cnt[r - l - fen.rangeSum(l, r + 1)]--;
        fen.add(pa[i], 1);
    }

    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] < 0) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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