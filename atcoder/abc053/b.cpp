#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;

    int pa = std::find(S.begin(), S.end(), 'A') - S.begin();
    int pz = std::find(S.rbegin(), S.rend(), 'Z') - S.rbegin();

    int ans = std::max(0, (int)S.size() - pz - pa);
    std::cout << ans << "\n";

    return 0;
}