#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, D;
    std::cin >> N >> D;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    i64 ans = 0;
    std::set<int> s;
    s.insert(-1E9);
    s.insert(2E9);
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N) {
            auto it = s.lower_bound(A[j]);
            if (1LL * *it - A[j] < D) {
                break;
            }
            it--;
            if (1LL * A[j] - *it < D) {
                break;
            }
            s.insert(A[j]);
            j++;
        }
        ans += j - i;
        s.erase(A[i]);
    }
    std::cout << ans << "\n";

    return 0;
}