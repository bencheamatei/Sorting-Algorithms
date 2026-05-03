#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

void custom_sort(std::vector<int> &a) {
    bool sortat=0;
    int n=(int)a.size();
    int* v=a.data();

    for(int it=0; !sortat && it<n; ++it) {
        sortat=true;
        int unde=it;
        for(int i=n-2; i>=it; --i) {
            if(v[i]>v[i+1]) {
                sortat=false;
                int tmp=v[i];
                v[i]=v[i+1];
                v[i+1]=tmp;
                unde=i;
            }
        }
        it=unde;
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