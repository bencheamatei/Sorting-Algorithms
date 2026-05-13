#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <chrono>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    int* v=a.data();

    int i=1;
    while(i<n) {
        int x=v[i];
        int j=i;
        while(j>0 && v[j-1]>x) {
            v[j]=v[j-1];
            j--;
        }

        v[j]=x; 
        ++i;
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