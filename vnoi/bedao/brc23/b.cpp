#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    if (N <= 2) {
        std::cout << S << "\n";
        return 0;
    }

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = S[i] - '0';
    }

    auto pa = a;
    std::vector<int> ppa;
    for (int t = 0; t < K; t++) {
        bool ok = 0;
        for (int i = 1; i < N - 1; i++) {
            if (pa[i - 1] == 1 && pa[i + 1] == 1) {
                ok = 1;
                a[i] ^= 1;
            }
        }

        if (!ok) {
            break;
        }
        
        if (a == ppa) {
            int k = K - t;
            if (k % 2 == 0) {
                a = pa;
                break;
            }
        }

        if (t >= 1) {
            ppa = pa;
        }
        pa = a;
    }

    for (int i = 0; i < N; i++) {
        std::cout << a[i];
    }
    std::cout << "\n";

    return 0;
}