#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    i64 ans = 0;

    std::map<i64, int> cnt;
    cnt[0] = 1;
    i64 sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        ans += cnt[sum];
        cnt[sum]++;
    }

    std::cout << ans << "\n";

    return 0;
}