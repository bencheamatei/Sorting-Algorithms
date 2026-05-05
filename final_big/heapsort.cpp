#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <chrono>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    if(n<=1)
        return;

    int st=n>>1;
    int dr=n;
    int* data=a.data();

    while(dr>1) {
        if(st>0) {
            st--;
        }
        else {
            dr--;
            int tmp=data[dr];
            data[dr]=data[0];
            data[0]=tmp;
        }

        int root=st;
        int val=data[root];
        int left_chld=(root<<1)|1;
        while(left_chld<dr) {
            int x=left_chld;
            if(x+1<dr && data[x]<data[x+1]) {
                x++;
            }

            if(val<data[x]) {
                data[root]=data[x];
                root=x;
                left_chld=(root<<1)|1;
            }   
            else 
                break;
        }
        data[root]=val;
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