#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());
    std::sort(B.begin(), B.end(), std::greater<int>());
    std::sort(C.begin(), C.end(), std::greater<int>());
    std::sort(D.begin(), D.end(), std::greater<int>());

    int lab = std::min(K, N * N);
    int lcd = std::min(K, N * N);

    auto work = [](const std::vector<int>& x, const std::vector<int>& y, int lim) {
        int n = x.size();
        std::vector<std::tuple<i64, int, int>> res;

        std::priority_queue<std::tuple<i64, int, int>> h;
        std::set<std::pair<int, int>> vis;

        h.push({x[0] + y[0], 0, 0});
        vis.insert({0, 0});

        while (!h.empty() && res.size() < lim) {
            auto [d, i, j] = h.top();
            h.pop();
            res.push_back({d, i, j});

            if (i + 1 < n && vis.find({i + 1, j}) == vis.end()) {
                h.push({x[i + 1] + y[j], i + 1, j});
                vis.insert({i + 1, j});
            }
            if (j + 1 < n && vis.find({i, j + 1}) == vis.end()) {
                h.push({x[i] + y[j + 1], i, j + 1});
                vis.insert({i, j + 1});
            }
        }

        return res;
    };

    auto ab = work(A, B, lab);
    auto cd = work(C, D, lcd);

    std::priority_queue<std::tuple<i64, int, int>> h;
    std::set<std::pair<int, int>> vis;

    h.push({std::get<0>(ab[0]) + std::get<0>(cd[0]), 0, 0});
    vis.insert({0, 0});

    int cnt = 0;
    int rp = 0, rq = 0;
    while (!h.empty()) {
        auto [d, p, q] = h.top();
        h.pop();
        cnt++;

        if (cnt == K) {
            rp = p;
            rq = q;
            break;
        }

        if (p + 1 < ab.size() && vis.find({p + 1, q}) == vis.end()) {
            h.push({std::get<0>(ab[p + 1]) + std::get<0>(cd[q]), p + 1, q});
            vis.insert({p + 1, q});
        }
        if (q + 1 < cd.size() && vis.find({p, q + 1}) == vis.end()) {
            h.push({std::get<0>(ab[p]) + std::get<0>(cd[q + 1]), p, q + 1});
            vis.insert({p, q + 1});
        }
    }

    auto [t1, a, b] = ab[rp];
    auto [t2, c, d] = cd[rq];
    std::cout << A[a] << " " << B[b] << " " << C[c] << " " << D[d] << "\n";

    return 0;
}