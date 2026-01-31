#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, c;
    std::cin >> r >> c;

    std::vector<std::string> s(r);
    for (int i = 0; i < r; i++) {
        std::cin >> s[i];
    }

    std::vector<std::array<int, 2>> p;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '#') {
                p.push_back({i, j});
            }
        }
    }
    assert(p.size() == 3);

    auto find = [&](int a, int b, int c) {
        return a + b + c - std::max({a, b, c}) - std::min({a, b, c});
    };
    int x = find(p[0][0], p[1][0], p[2][0]);
    int y = find(p[0][1], p[1][1], p[2][1]);

    std::queue<std::array<int, 2>> q;
    for (auto [a, b] : p) {
        q.push({a, b});
    }

    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();

        s[a][b] = '#';
        if (a == x && b == y) {
            continue;
        }

        if (a < x) {
            q.push({a + 1, b});
        } else if (a > x) {
            q.push({a - 1, b});
        } else if (b < y) {
            q.push({a, b + 1});
        } else {
            q.push({a, b - 1});
        }
    }

    for (int i = 0; i < r; i++) {
        std::cout << s[i] << "\n";
    }

    return 0;
}