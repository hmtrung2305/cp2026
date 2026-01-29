#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> s(N + 1);
    for (int i = 0; i < N; i++) {
        s[i + 1] = s[i] + A[i];
    }

    for (int i = 0; i < Q; i++) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x;
            std::cin >> x;
            x--;
            s[x + 1] += A[x + 1] - A[x];
            std::swap(A[x], A[x + 1]);
        } else {
            int l, r;
            std::cin >> l >> r;
            l--;
            std::cout << s[r] - s[l] << "\n";
        }
    }

    return 0;
}