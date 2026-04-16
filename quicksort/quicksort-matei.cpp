#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

void custom_sort(std::vector<int> &a) {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }

    custom_sort(a);
    assert(std::ranges::is_sorted(a));
    return 0;
}