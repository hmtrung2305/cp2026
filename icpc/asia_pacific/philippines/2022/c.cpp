#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    {
        std::map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        for (int i = 0; i < n; i++) {
            a[i] = cnt[a[i]];
        }
    }

    for (int i = 1; i < k; i++) {
        std::vector<int> na(n);
        std::vector<int> cnt(n + 1);
        for (int j = 0; j < n; j++) {
            cnt[a[j]]++;
        }
        for (int j = 0; j < n; j++) {
            na[j] = cnt[a[j]];
        }
        if (a == na) {
            break;
        }
        std::swap(a, na);
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}