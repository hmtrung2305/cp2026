#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::pair<int, int>> x_moves, o_moves;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'x') {
                x_moves.push_back({i, j});
            } else if (a[i][j] == 'o') {
                o_moves.push_back({i, j});
            }
        }
    }

    if (std::abs((long long) x_moves.size() - (long long) o_moves.size()) > 1) {
        // std::cerr << "!here\n";
        std::cout << "NIE\n";
        return;
    }

    std::vector<std::pair<int, int>> dirs = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

    auto check_win = [&](std::vector<std::string> &a, char c) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto [dx, dy] : dirs) {
                    int cnt = 0;
                    int x = i;
                    int y = j;
                    while (0 <= x && x < n && 0 <= y && y < n && a[x][y] == c) {
                        ++cnt;
                        x += dx;
                        y += dy;
                    }
                    if (cnt == k) {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    bool is_x_win = check_win(a, 'x');
    bool is_o_win = check_win(a, 'o');
    if (is_x_win && is_o_win) {
        // std::cerr << "!here\n";
        std::cout << "NIE\n";
        return;
    }

    if (!is_x_win && !is_o_win) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == '.') {
                    std::cout << "NIE\n";
                    return;
                }
            }
        }

        std::cout << "TAK\n";
        int x_turn = 0, o_turn = 0;
        while (x_turn < (int) x_moves.size() && o_turn < (int) o_moves.size()) {
            std::cout << x_moves[x_turn].first + 1 << ' ' << x_moves[x_turn].second + 1 << '\n';
            ++x_turn;

            std::cout << o_moves[o_turn].first + 1 << ' ' << o_moves[o_turn].second + 1 << '\n';
            ++o_turn;
        }

        if (x_turn < (int) x_moves.size()) {
            std::cout << x_moves[x_turn].first + 1 << ' ' << x_moves[x_turn].second + 1 << '\n';
            ++x_turn;
        }

        if (o_turn < (int) o_moves.size()) {
            std::cout << o_moves[o_turn].first + 1 << ' ' << o_moves[o_turn].second + 1 << '\n';
            ++o_turn;
        }

        return;
    }

    char who_fist = '?';
    if (x_moves.size() == o_moves.size()) {
        if (is_x_win) {
            who_fist = 'o';
        } else {
            who_fist = 'x';
        }
    } else {
        if (x_moves.size() > o_moves.size()) {
            who_fist = 'x';
        } else {
            who_fist = 'o';
        }
    }

    char who_win = '?';
    if (is_x_win) {
        who_win = 'x';
    } else {
        who_win = 'o';
    }

    std::pair<int, int> last_move = [&]() -> std::pair<int, int> {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto b = a;
                if (b[i][j] == who_win) {
                    b[i][j] = '.';
                }
                if (!check_win(b, who_win)) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }();

    if (last_move.first == -1 && last_move.second == -1) {
        // std::cerr << "!here\n";
        std::cout << "NIE\n";
        return;
    }

    std::cout << "TAK\n";
    int x_turn = 0, o_turn = 0;
    while (x_turn < (int) x_moves.size() && o_turn < (int) o_moves.size()) {
        if (who_fist == 'x') {
            if (x_moves[x_turn] == last_move) {
                ++x_turn;
            }
            std::cout << x_moves[x_turn].first + 1 << ' ' << x_moves[x_turn].second + 1 << '\n';
            ++x_turn;

            if (o_moves[o_turn] == last_move) {
                ++o_turn;
            }
            std::cout << o_moves[o_turn].first + 1 << ' ' << o_moves[o_turn].second + 1 << '\n';
            ++o_turn;
        } else {
            if (o_moves[o_turn] == last_move) {
                ++o_turn;
            }
            std::cout << o_moves[o_turn].first + 1 << ' ' << o_moves[o_turn].second + 1 << '\n';
            ++o_turn;

            if (x_moves[x_turn] == last_move) {
                ++x_turn;
            }
            std::cout << x_moves[x_turn].first + 1 << ' ' << x_moves[x_turn].second + 1 << '\n';
            ++x_turn;
        }
    }
    std::cout << last_move.first + 1 << ' ' << last_move.second + 1 << '\n';
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