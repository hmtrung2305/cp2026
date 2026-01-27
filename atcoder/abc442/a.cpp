#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;

    int ans = std::count(S.begin(), S.end(), 'i');
    ans += std::count(S.begin(), S.end(), 'j');

    std::cout << ans << "\n";

    return 0;
}