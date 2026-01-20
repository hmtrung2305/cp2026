#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    const int B = 30;
    std::vector<std::vector<int>> pre(30);
    for (int b = B - 1; b >= 0; b--) {
        std::vector<int> b0, b1;
        int cntl = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] >> b & 1) {
                b1.push_back(a[i]);
            } else {
                cntl++;
                b0.push_back(a[i]);
            }
            pre[b].push_back(cntl);
        }
        std::swap(a, b0);
        a.insert(a.end(), b1.begin(), b1.end());
    }

    auto query = [&](int l, int r, int k) {
        int ans = 0;
        for (int b = B - 1; b >= 0; b--) {
            int pr = r == 0 ? 0 : pre[b][r - 1];
            int pl = l == 0 ? 0 : pre[b][l - 1];
            int cntl = pr - pl;
            if (k < cntl) {
                l = pl;
                r = pr;
            } else {
                k -= cntl;
                l = pre[b][N - 1] - pl + l;
                r = pre[b][N - 1] - pr + r;
                ans |= 1 << b;
            }
        }
        return ans;
    };

    for (int i = 0; i < Q; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << query(l, r, k) << "\n";
    }

    return 0;
}