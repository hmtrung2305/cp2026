#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mn1 = 2E9, mn2 = 2E9;
    for (int i = 0; i < n; i++) {
        if (a[i] < mn1) {
            mn2 = mn1;
            mn1 = a[i];
        } else if (a[i] > mn1 && a[i] < mn2) {
            mn2 = a[i];
        }
    }

    std::cout << (mn2 / 2 >= mn1 ? mn1 : mn1 / 2) << "\n";

    return 0;
}