#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    int st=n>>1;
    int dr=n;

    while(dr>1) {
        if(st>0) {
            st--;
        }
        else {
            dr--;
            std::swap(a[dr],a[0]);
        }

        int root=st;
        while(2*root+1<dr) {
            int x=2*root+1;
            if(x+1<dr && a[x]<a[x+1]) {
                x++;
            }

            if(a[root]<a[x]) {
                std::swap(a[root],a[x]);
                root=x;
            }   
            else 
                break;
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