#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        a[i] = std::min(a[i], K);
    }

    std::vector<std::bitset<5001>> pre(N + 1), suf(N + 1);
    pre[0].set(0);
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] | (pre[i] << a[i]);
    }
    suf[N].set(0);
    for (int i = N - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] | (suf[i + 1] << a[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool ok = 0;
        int l = K - a[i], r = K;
        for (int j = l; j < r; j++) {
            ok |= pre[i][j];
        }
        for (int j = 0; j < l; j++) {
            if (!pre[i][j]) {
                continue;
            }
            int x = suf[i + 1]._Find_next(l - j - 1);
            if (x != suf[i + 1].size() && j + x < r) {
                ok = 1;
                break;
            }
        }
        ans += ok;
    }
    std::cout << N - ans << "\n";

    return 0;
}