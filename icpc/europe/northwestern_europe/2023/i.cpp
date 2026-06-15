#include <bits/stdc++.h>

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int k;
    std::cin >> k;

    int cnt = 0;
    auto ask = [&](int l, int r) {
        std::cout << l << " " << r << "\n";
        int x;
        std::cin >> x;
        k = x;
        cnt++;
        return x;
    };

    std::vector<int> p;
    for (int c = 1; c < n; c++) {

        std::vector<std::string> s{"0", "1"};
        for (int i = 2; i <= n - c; i++) {
            std::vector<std::string> t;
            int m = s.size();
            for (int j = 0; j < m; j++) {
                t.push_back('0' + s[j]);
            }
            for (int j = m - 1; j >= 0; j--) {
                t.push_back('1' + s[j]);
            }
            s.swap(t);
        }

        for (int i = 0; i < s.size(); i++) {
            int pk = k;
            if (i > 0) {
                for (int j = 0; j < s[i].size(); j++) {
                    if (s[i][j] != s[i - 1][j]) {
                        pk = ask(c, c + 1 + j);
                        if (pk == n) {
                            return 0;
                        }
                    }
                }
            }
            int nk = ask(c, c);
            if (nk == n) {
                return 0;
            }
            if (nk == pk + 1) {
                break;
            } else if (nk == pk - 1) {
                p.push_back(c);
                break;
            }
        }
    }

    int pk = k;
    for (int i = 0; i < p.size(); i++) {
        int nk = ask(p[i], p[i]);
        assert(nk == pk + 1);
        pk = nk;
    }

    if (k == n - 1) {
        ask(n, n);
        return 0;
    }

    assert(k == n);
    assert(cnt <= 2500);

    return 0;
}