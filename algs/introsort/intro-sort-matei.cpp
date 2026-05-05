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

void insertion_sort(std::vector<int> &a, int left,int right) {
    int i=left+1;
    while(i<=right) {
        int x=a[i];
        int j=i;
        while(j>left && a[j-1]>x) {
            a[j]=a[j-1];
            j--;
        }
        a[j]=x; 
        ++i;
    }
}   

void heap_sort(std::vector<int> &a,int left,int right) {
    int st=left+((right-left+1)>>1);
    int dr=right+1;

    while(dr>left+1) {
        if(st>left) {
            st--;
        }
        else {
            dr--;
            std::swap(a[dr],a[left]);
        }

        int root=st;
        while(left+2*(root-left)+1<dr) {
            int x=left+2*(root-left)+1;
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

void intro_sort(std::vector<int> &a, int st,int dr, int depth) {
    if(dr-st+1<16) {
        insertion_sort(a,st,dr);
    }
    else if(depth==0) {
        heap_sort(a,st,dr);
    }
    else {
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

        intro_sort(a,st,low-1,depth-1);
        intro_sort(a,gre+1,dr,depth-1);
    }
}

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    int p=1;
    int cnt=0;
    while(p<=n) {
        p<<=1;
        cnt++;
    }
    intro_sort(a,0,n-1,cnt);
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