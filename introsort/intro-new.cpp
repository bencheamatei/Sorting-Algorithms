#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <random>

std::mt19937 gen;
int get_nr(int st, int dr)
{
    std::uniform_int_distribution<> distrib(st, dr);
    return distrib(gen);
}

int median_of_three(int* a, int st, int dr) {
    int p1=get_nr(st,dr),p2=get_nr(st,dr),p3=get_nr(st,dr);
    if(a[p1]>a[p3]) {
        // std::swap(a[p1],a[p3]);
        int tmp=a[p1];
        a[p1]=a[p3];
        a[p3]=tmp;
    }
    if(a[p2]<=a[p1])
        return p1;
    if(a[p2]<=a[p3])
        return p2;
    return p3;
}

void insertion_sort(int *a, int left,int right) {
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

void heap_sort(int *a,int left,int right) {
    int st=left+((right-left+1)>>1);
    int dr=right+1;

    while(dr>left+1) {
        if(st>left) {
            st--;
        }
        else {
            dr--;
            // std::swap(a[dr],a[left]);
            int tmp=a[dr];
            a[dr]=a[left];
            a[left]=tmp;
        }

        int root=st;
        while(left+2*(root-left)+1<dr) {
            int x=left+2*(root-left)+1;
            if(x+1<dr && a[x]<a[x+1]) {
                x++;
            }

            if(a[root]<a[x]) {
                // std::swap(a[root],a[x]);
                int tmp=a[root];
                a[root]=a[x];
                a[x]=tmp;
                root=x;
            }   
            else 
                break;
        }
    }
}  

void intro_sort(int *a, int st,int dr, int depth) {
    while(st<dr) {
        int n=dr-st+1;
        if(n<17) {
            insertion_sort(a,st,dr);
            return;
        }

        if(depth==0) {
            heap_sort(a,st,dr);
            return;
        }
        depth--;

        int pivot_idx=median_of_three(a,st,dr);
        int low=st;
        int gre=dr;
        int i=st+1;
        // std::swap(a[pivot_idx],a[st]);
        int tmp=a[pivot_idx];
        a[pivot_idx]=a[st];
        a[st]=tmp;

        int pivot=a[st];

        while(i<=gre) {
            if(a[i]<pivot) {
                // std::swap(a[low],a[i]);
                int tmp=a[low];
                a[low]=a[i];
                a[i]=tmp;
                low++;
                i++;
            }
            else if(a[i]>pivot) {
                // std::swap(a[gre],a[i]);
                int tmp=a[gre];
                a[gre]=a[i];
                a[i]=tmp;
                gre--;
            }   
            else {
                i++;
            }
        }

        if(low-st<=dr-gre) {
            intro_sort(a,st,low-1,depth);
            st=gre+1;
        }   
        else {
            intro_sort(a,gre+1,dr,depth);
            dr=low-1;
        }
    }
}

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    std::random_device rd;
    gen.seed(rd());
    int p=1;
    int cnt=0;
    while(p<=n) {
        p<<=1;
        cnt++;
    }
    int *v=a.data();
    intro_sort(v,0,n-1,2*cnt);
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