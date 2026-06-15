#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    bool full = 1;
    int cx = 0, co = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            full &= s[i] != '.';
            cx += s[i] == 'x';
            co += s[i] == 'o';
        }
    }

    if (std::abs(cx - co) > 1) {
        std::cout << "NIE\n";
        return;
    }

    {
        bool xw = 0, ow = 0;
        int si = -1, sj = -1;
        for (int i = 0; i < n - k; i++) {
            for (int j = 0; j < n; j++) {
                bool c = 1;
                for (int x = 0; x < k; x++) {
                    c &= s[i][j + x] == s[i][j];
                }
                if (c) {
                    if (s[i][j] == 'x') {
                        xw = 1;
                    } else {
                        ow = 1;
                    }
                    si = i;
                    sj = j;
                }
            }
        }
        if (xw && ow) {
            std::cout << "NIE\n";
            return;
        }
        if (xw && cx < co) {
            std::cout << "NIE\n";
            return;
        }

        
    }

    {

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