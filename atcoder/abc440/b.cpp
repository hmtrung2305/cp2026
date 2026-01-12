#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::array<int, 2>> a(N);
    for (int i = 0; i < N; i++) {
        int T;
        std::cin >> T;
        a[i] = {T, i};
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < 3; i++) {
        std::cout << a[i][1] + 1 << " \n"[i == 2];
    }

    return 0;
}