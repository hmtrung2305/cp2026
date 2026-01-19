#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L, U;
    std::cin >> N >> L >> U;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    auto calc = [&](int x) {
        if (x == 0) {
            return 0LL;
        }

        i64 res = 0;
        std::map<int, int> m;
        int cnt = 0;
        for (int i = 0, j = 0; i < N; i++) {
            cnt += m[a[i]]++ == 0;
            while (j < i && cnt > x) {
                cnt -= --m[a[j]] == 0;
                j++;
            }
            res += i - j + 1;
        }
        return res;
    };

    i64 ans = calc(U) - calc(L - 1);
    std::cout << ans << "\n";

    return 0;
}