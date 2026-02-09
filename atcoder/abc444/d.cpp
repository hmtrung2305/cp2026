#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    const int L = 200200;
    std::vector<int> pre(L);
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        pre[0]++;
        pre[A]--;
    }

    for (int i = 0; i < L - 1; i++) {
        pre[i + 1] += pre[i];
    }
    for (int i = 0; i < L - 1; i++) {
        pre[i + 1] += pre[i] / 10;
        pre[i] %= 10;
    }

    while (pre.back() == 0) {
        pre.pop_back();
    }

    std::reverse(pre.begin(), pre.end());
    for (int i = 0; i < pre.size(); i++) {
        std::cout << pre[i];
    }
    std::cout << "\n";

    return 0;
}