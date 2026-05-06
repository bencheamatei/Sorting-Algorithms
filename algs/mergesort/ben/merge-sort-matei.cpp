#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <chrono>

void merge_sort(int* &a,int* &tmp,int st,int dr) {
    if(st>=dr) 
        return ;

    int mij=(st+dr)>>1;
    merge_sort(a,tmp,st,mij);
    merge_sort(a,tmp,mij+1,dr);

    int i=st;
    int j=mij+1;
    int u=0;
    while(i<=mij && j<=dr) {
        if(a[i]<a[j]) {
            tmp[u++]=a[i++];
        }
        else {
            tmp[u++]=a[j++];
        }
    }

    while(i<=mij) {
        tmp[u++]=a[i++];
    }

    while(j<=dr) {
        tmp[u++]=a[j++];
    }

    for(int k=st; k<=dr; k++) {
        a[k]=tmp[k-st];
    }
}

void custom_sort(std::vector<int> &a) {
    std::vector<int> tmp((int)a.size());
    int* ap=a.data();
    int* tmpp=tmp.data();
    merge_sort(ap,tmpp,0,(int)a.size()-1);
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