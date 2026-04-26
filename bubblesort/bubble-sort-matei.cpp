#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

void custom_sort(std::vector<int> &a) {
    bool sortat=0;
    int n=(int)a.size();

   for(int it=0; !sortat && it<n; ++it) {
        sortat=1;
        for(int i=n-2; i>=it; --i) {
            if(a[i]>a[i+1]) {
                sortat=0;
                std::swap(a[i],a[i+1]);
            }
        }
    }
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