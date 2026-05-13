#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <chrono>

void custom_sort(std::vector<int> &a) {
    bool sortat=0;
    int n=(int)a.size();
    int* v=a.data();

    for(int unde=0; !sortat && unde<n;) {
        sortat=true;
        int u=-1;
        for(int i=n-2; i>=unde; --i) {
            if(v[i]>v[i+1]) {
                sortat=false;
                int tmp=v[i];
                v[i]=v[i+1];
                v[i+1]=tmp;
                u=i;
            }
        }
        unde=u;
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

    auto start=std::chrono::high_resolution_clock::now();
    custom_sort(a);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << "\n";
    assert(std::ranges::is_sorted(a));
    return 0;
}