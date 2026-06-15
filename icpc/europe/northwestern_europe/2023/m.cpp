#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;

    for (int i = 0; i < (int) a.size(); ++i) {
        a[i] = std::tolower(a[i]);
    }
    for (int i = 0; i < (int) b.size(); ++i) {
        b[i] = std::tolower(b[i]);
    }

    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    int i = 0, j = 0;
    while (i < (int) a.size()) {
        while (j < (int) b.size() && a[i] != b[j] && std::find(vowels.begin(), vowels.end(), b[j]) != vowels.end()) {
            ++j;
        }
        if (j >= (int) b.size() || a[i] != b[j]) {
            std::cout << "Different\n";
            return 0;
        }
        ++i;
        ++j;
        // std::cerr << a[i] << ' ' << b[j]  << '\n';
    }
    while (j < (int) b.size() && std::find(vowels.begin(), vowels.end(), b[j]) != vowels.end()) {
        ++j;
    }
    
    if (i >= (int) a.size() && j >= (int) b.size()) {
        std::cout << "Same\n";
    } else {
        std::cout << "Different\n";
    }

    return 0;
}