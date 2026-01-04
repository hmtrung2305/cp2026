#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L;
    std::cin >> N >> L;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    std::sort(S.begin(), S.end());

    for (int i = 0; i < N; i++) {
        std::cout << S[i];
    }
    std::cout << "\n";

    return 0;
}