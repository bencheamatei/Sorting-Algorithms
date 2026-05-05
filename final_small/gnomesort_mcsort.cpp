#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    int pos=1;
    int nxt=2;
    int* v=a.data();
    while(pos<n) {
        if(pos==0 || v[pos]>=v[pos-1]) {
            pos++;
        }
        else {
            int tmp=v[pos];
            v[pos]=v[pos-1];
            v[pos-1]=tmp;
            pos--;
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