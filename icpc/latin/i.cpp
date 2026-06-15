#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string T;
    std::cin >> T;

    int N;
    std::cin >> N;

    int s = 6;
    if (T[0] == 'M') {
        s = 0;
    } else if (T[0] == 'T' && T[1] == 'u') {
        s = 1;
    } else if (T[0] == 'W') {
        s = 2;
    } else if (T[0] == 'T' && T[1] == 'h') {
        s = 3;
    } else if (T[0] == 'F') {
        s = 4;
    } else if (T[0] == 'S' && T[1] == 'a') {
        s = 5;
    }

    int a[7] = {2, 3, 4, 0, 0, 0, 0};
    int b[7] = {30, 30, 30, 32, 31, 0, 0};

    int ans = 32;
    for (int i = 0; i < N; i++) {
        int D;
        std::cin >> D;

        int x = ((s - D) % 7 + 7) % 7;
        if (D <= 100) {
            while (D > b[x]) {
                D -= b[x];
                x = a[x];
            }
            ans = std::min(ans, b[x] - D);
        } else {
            while (x) { 
                D -= b[x];
                x = a[x];
            }
            D %= 91;
            while (D > b[x]) {
                D -= b[x];
                x = a[x];
            }
            ans = std::min(ans, b[x] - D);
        }
    }

    std::cout << ans << "\n";

    return 0;
}