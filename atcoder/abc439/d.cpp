#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    i64 ans = 0;

    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        m[A[i]]++;
        if (A[i] % 5 == 0) {
            ans += 1LL * m[A[i] / 5 * 7] * m[A[i] / 5 * 3];
        }
    }
    m.clear();
    for (int i = N - 1; i >= 0; i--) {
        m[A[i]]++;
        if (A[i] % 5 == 0) {
            ans += 1LL * m[A[i] / 5 * 7] * m[A[i] / 5 * 3];
        }
    }

    std::cout << ans << "\n";

    return 0;
}