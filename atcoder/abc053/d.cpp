#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int cnt = std::unique(A.begin(), A.end()) - A.begin();
    std::cout << cnt - (cnt % 2 == 0 ? 1 : 0) << "\n";

    return 0;
}