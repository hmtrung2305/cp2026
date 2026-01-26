#include <bits/stdc++.h>

void solve() {
    std::string A, B;
    std::cin >> A >> B;

    if (A == B) {
        std::cout << "YES\n";
        return;
    }

    int pA = std::count(A.begin(), A.end(), 'P');
    int pB = std::count(B.begin(), B.end(), 'P');

    if (!pA || pA != pB) {
        std::cout << "NO\n";
        return;
    }

    while (A.back() == B.back()) {
        if (A.back() == 'P') {
            std::cout << "YES\n";
            return;
        }
        A.pop_back();
        B.pop_back();
    }
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}