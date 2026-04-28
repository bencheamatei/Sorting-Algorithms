#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <random>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }

    sort(a.begin(),a.end());
    assert(std::ranges::is_sorted(a));
    return 0;
}
