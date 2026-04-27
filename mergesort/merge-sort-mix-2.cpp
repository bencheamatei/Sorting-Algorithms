#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

void merge_sort(std::vector<int> &a,std::vector<int> &tmp,int st,int dr) {
    if(st>=dr) 
        return ;

    int mij=(st+dr)>>1;
    merge_sort(a,tmp,st,mij);
    merge_sort(a,tmp,mij+1,dr);

    int i=st;
    int j=mij+1;
    int u=0;
    tmp.clear();
    while(i<=mij && j<=dr) {
        if(a[i]<a[j]) {
            tmp.push_back(a[i++]);
        }
        else {
            tmp.push_back(a[j++]);
        }
    }

    while(i<=mij) {
        tmp.push_back(a[i++]);
    }

    while(j<=dr) {
        tmp.push_back(a[j++]);
    }

    for(int k=st; k<=dr; k++) {
        a[k]=tmp[k-st];
    }
}

void custom_sort(std::vector<int> &a) {
    std::vector<int> tmp;
    merge_sort(a,tmp,0,(int)a.size()-1);
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