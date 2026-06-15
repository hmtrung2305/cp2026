#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i]--;
    }

    std::vector<int> pa(n), pb(n);
    for (int i = 0; i < n; i++) {
        pa[a[i]] = i;
        pb[b[i]] = i;
    }

    int cnt = 0;
    std::vector<int> c(n - 1);

    auto update = [&](int x) {
        if (x < 0 || x >= n - 1) {
            return;
        }
        cnt -= c[x];
        c[x] = pa[b[x]] > pa[b[x + 1]];
        cnt += c[x];
    };
    auto answer = [&]() {
        std::cout << 1LL * cnt * n + pa[b[n - 1]] + 1 - n << "\n";
    };

    for (int i = 0; i < n - 1; i++) {
        update(i);
    }
    answer();

    for (int i = 1; i < d; i++) {
        int c, x, y;
        std::cin >> c >> x >> y;
        x--;
        y--;

        if (c == 1) {
            std::swap(a[x], a[y]);
            std::swap(pa[a[x]], pa[a[y]]);
            update(pb[a[x]] - 1);
            update(pb[a[x]]);
            update(pb[a[y]] - 1);
            update(pb[a[y]]);
        } else {
            std::swap(b[x], b[y]);
            std::swap(pb[b[x]], pb[b[y]]);
            update(x - 1);
            update(x);
            update(y - 1);
            update(y);
        }

        answer();
    }

    return 0;
}