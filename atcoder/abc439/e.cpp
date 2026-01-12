#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<int> p(N);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](int i, int j) {
            if (A[i] == A[j]) {
                return B[i] > B[j];
            }
            return A[i] < A[j];
        });

    std::vector<int> dp;
    for (auto i : p) {
        int j = std::lower_bound(dp.begin(), dp.end(), B[i]) - dp.begin();
        if (j == dp.size()) {
            dp.push_back(B[i]);
        } else {
            dp[j] = B[i];
        }
    }
    std::cout << dp.size() << "\n";

    return 0;
}