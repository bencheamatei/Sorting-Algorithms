#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <chrono>

void merge(int *a,int *b, int st,int mij,int dr) {
    int i=st;
    int j=mij;
    int curr=st;

    while(i<mij && j<dr) {
        if(a[i]<a[j]) {
            b[curr++]=a[i++];
        }
        else {
            b[curr++]=a[j++];
        }
    }

    while(i<mij) {
        b[curr++]=a[i++];
    }
    while(j<dr) {
        b[curr++]=a[j++];
    }
}

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    std::vector<int> aux(n);

    int *src=a.data();
    int *dest=aux.data();

    for(int sz=1; sz<n; sz<<=1) {
        for(int st=0; st<n; st+=(sz<<1)) {
            int mij=std::min(st+sz,n);
            int dr=std::min(st+(sz<<1),n);
            merge(src,dest,st,mij,dr);
        }
        std::swap(src,dest);
    }

    if(src!=a.data()) {
        for(int i=0; i<n; i++) {
            a[i]=src[i];
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

    auto start=std::chrono::high_resolution_clock::now();
    custom_sort(a);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << "\n";
    assert(std::ranges::is_sorted(a));
    return 0;
}