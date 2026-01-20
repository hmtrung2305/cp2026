#include <bits/stdc++.h>

struct Node {
    Node *l = nullptr;
    Node *r = nullptr;
    int cnt = 0;
};

Node *modify(Node *t, int l, int r, int x, int v) {
    Node *t1 = new Node;
    if (t) {
        *t1 = *t;
    }
    t1->cnt++;
    if (r - l > 1) {
        int m = (l + r) / 2;
        if (x < m) {
            t1->l = modify(t1->l, l, m, x, v);
        } else {
            t1->r = modify(t1->r, m, r, x, v);
        }
    }
    return t1;
}

int query(Node *t, int l, int r, int x, int y) {
    if (l >= y || r <= x || !t) {
        return 0;
    }
    if (l >= x && r <= y) {
        return t->cnt;
    }
    int m = (l + r) / 2;
    return query(t->l, l, m, x, y) + query(t->r, m, r, x, y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> p(N);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](int i, int j) {
            return A[i] < A[j];
        });

    auto v = A;
    std::sort(v.begin(), v.end());

    std::vector<Node *> tree(N + 1);
    for (int i = 0; i < N; i++) {
        tree[i + 1] = modify(tree[i], 0, N, p[i], A[p[i]]);
    }

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        int L, R, X;
        std::cin >> L >> R >> X;
        L--;
        X = std::lower_bound(v.begin(), v.end(), X + 1) - v.begin();
        int ans = R - L - query(tree[X], 0, N, L, R);
        std::cout << ans << "\n";
    }

    return 0;
}