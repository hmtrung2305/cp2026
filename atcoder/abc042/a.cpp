#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B, C;
    std::cin >> A >> B >> C;

    std::vector<int> a{A, B, C};
    std::sort(a.begin(), a.end());

    if (a[0] == 5 && a[1] == 5 && a[2] == 7) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}