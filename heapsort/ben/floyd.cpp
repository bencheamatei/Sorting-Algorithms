#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <chrono>

void shift_down(std::vector<int> &a,int nod,int dr) {
    int val=a[nod];
    while(2*nod+1<dr) {
        int x=2*nod+1;
        if(x+1<dr && a[x]<a[x+1]) {
            x++;
        }

        if(val<a[x]) {
            a[nod]=a[x];
            nod=x;
        }
        else 
            break;
    }
    a[nod]=val;
}

void shift_down2(std::vector<int> &a,int nod,int dr) {
    int fr=nod;
    int val=a[nod];
    while(2*fr+1<dr) {
        int x=2*fr+1;
        if(x+1<dr && a[x]<a[x+1]) {
            x++;
        }
        a[fr]=a[x];
        fr=x;
    }
    a[fr]=val;

    int curr=fr;
    while(curr>nod) {
        int par=(curr-1)>>1;
        if(a[curr]>a[par]) {
            std::swap(a[curr],a[par]);
            curr=par;
        }
        else 
            break;
    }
}

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    for(int i=(n>>1)-1; i>=0; i--) {
        shift_down(a,i,n);
    }

    for(int dr=n-1; dr; dr--) {
        std::swap(a[dr],a[0]);
        shift_down2(a,0,dr);
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