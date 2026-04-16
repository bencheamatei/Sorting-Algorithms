#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(auto &x:a) {
        std::cin >> x;
    }

    sort(a.begin(),a.end());
    assert(std::ranges::is_sorted(a));

    return 0;
}