#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

int mediana(std::vector<int> &a,int st,int dr) {
    int mij=(st+dr)>>1;
    if(a[st]>a[dr])
        std::swap(a[st],a[dr]);
    if(a[st]<=a[mij] && a[mij]<=a[dr])
        return mij;
    if(a[mij]<=a[st])
        return st;
    return dr;
}

void quick_sort(std::vector<int> &a,int st,int dr) {
    if(st>=dr)
        return ;

    int pivot_idx=mediana(a,st,dr);
    int low=st;
    int gre=dr;
    int i=st+1;
    std::swap(a[pivot_idx],a[st]);
    int pivot=a[st];

    while(i<=gre) {
        if(a[i]<pivot) {
            std::swap(a[low],a[i]);
            low++;
            i++;
        }
        else if(a[i]>pivot) {
            std::swap(a[gre],a[i]);
            gre--;
        }   
        else {
            i++;
        }
    }

    quick_sort(a,st,low-1);
    quick_sort(a,gre+1,dr);
}

void custom_sort(std::vector<int> &a) {
    quick_sort(a,0,(int)a.size()-1);
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