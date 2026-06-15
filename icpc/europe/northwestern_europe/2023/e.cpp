#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    auto attack = [&](int x1, int y1, int x2, int y2) {
        if (x1 == x2 || y1 == y2 || x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2) {
            return true;
        }
        return false;
    };

    int p = 0;
    for (int i = 1; i < n; i++) {
        if (!attack(x[i], y[i], x[0], y[0])) {
            p = i;
            break;
        }
    }

    if (p == 0) {
        std::cout << "YES\n";
        std::cout << x[0] << " " << y[0] << "\n";
        return;
    }

    std::vector<std::array<int, 2>> seq;
    seq.push_back({x[0], y[p]});
    seq.push_back({x[p], y[0]});
    seq.push_back({x[0], y[p] + std::abs(x[0] - x[p])});
    seq.push_back({x[0], y[p] - std::abs(x[0] - x[p])});
    seq.push_back({x[p] + abs(y[0] - y[p]), y[0]});
    seq.push_back({x[p] - abs(y[0] - y[p]), y[0]});
    seq.push_back({x[p], y[0] + std::abs(x[0] - x[p])});
    seq.push_back({x[p], y[0] - std::abs(x[0] - x[p])});
    seq.push_back({x[0] + std::abs(y[0] - y[p]), y[p]});
    seq.push_back({x[0] - std::abs(y[0] - y[p]), y[p]});

    int d1 = x[0] + y[0] + x[p] - y[p];
    int d2 = x[0] + y[0] - x[p] + y[p];
    if (d1 % 2 == 0 && d2 % 2 == 0) {
        seq.push_back({d1 / 2, d2 / 2});
    }

    d1 = x[p] + y[p] + x[0] - y[0];
    d2 = x[p] + y[p] - x[0] + y[0];
    if (d1 % 2 == 0 && d2 % 2 == 0) {
        seq.push_back({d1 / 2, d2 / 2});
    }

    std::vector<bool> ok(seq.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < seq.size(); j++) {
            auto [cx, cy] = seq[j];
            if (!attack(x[i], y[i], cx, cy)) {
                ok[j] = 1;
            }
        }
    }

    for (int i = 0; i < seq.size(); i++) {
        auto [cx, cy] = seq[i];
        if (!ok[i]) {
            std::cout << "YES\n";
            std::cout << cx << " " << cy << "\n";
            return;
        }
    }
    std::cout << "NO\n";
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