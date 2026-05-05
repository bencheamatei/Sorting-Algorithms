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

int median_of_three(std::vector<int>& a, int i, int j,int k) {
    if(a[i]<=a[k]) {
        if(a[j]<=a[i])
            return i;
        if(a[j]<=a[k])
            return j;
        return k;
    }
    else {
        // a[k] < a[i]
        if(a[j]<=a[k])
            return k;
        if(a[j]<=a[i])
            return j;
        return i;
    }
}

int ninther(std::vector<int>& a,int st,int dr) {
    int mij=(st+dr)>>1;
    if(dr-st+1<=40) {
        return median_of_three(a,st,mij,dr);
    }

    int p=(dr-st+1)>>3;
    int u1=median_of_three(a,st,st+p,st+2*p);
    int u2=median_of_three(a,mij-p,mij,mij+p);
    int u3=median_of_three(a,dr-2*p,dr-p,dr);
    return median_of_three(a,u1,u2,u3);
}

void quicksort(std::vector<int>& a, int st, int dr) {
    while(st<dr) {
        int pivot_idx=ninther(a,st,dr);
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

        if(low-st<=dr-gre) {
            quicksort(a,st,low-1);
            st=gre+1;
        }   
        else {
            quicksort(a,gre+1,dr);
            dr=low-1;
        }
    }
}

void custom_sort(std::vector<int> &a) {
    quicksort(a,0,(int)a.size()-1);
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
