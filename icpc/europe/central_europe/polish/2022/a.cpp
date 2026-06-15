#include <bits/stdc++.h>

int cnt_digit(int x) {
    if (x == 0) {
        return 0;
    }
    int cnt = 0;
    while (x > 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    for (int l = 1; l <= 7; l++) {
        for (int x = 0; x <= l; x++) {
            for (int y = 0; y <= l - x; y++) {
                int z = l - x - y;
                std::map<std::string, int> cnt;
                int mx = 0;
                for (int i = 0; i < n; i++) {
                    std::string s = a[i].substr(0, std::min(x, (int)a[i].size())) + b[i].substr(0, std::min(y, (int)b[i].size()));
                    std::cerr << s << "\n";
                    cnt[s]++;
                    mx = std::max(mx, cnt[s]);
                }
                if (cnt_digit(mx - 1) <= z) {
                    std::cout << x << " " << y << " " << z << "\n";
                    return;
                }
            }
        }
    }
    assert(false);
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