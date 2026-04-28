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

int median_of_three(std::vector<int>& a, int st, int dr) {
    int p1=get_nr(st,dr),p2=get_nr(st,dr),p3=get_nr(st,dr);
    if(a[p1]>a[p3]) {
        std::swap(a[p1],a[p3]);
    }
    if(a[p2]<=a[p1])
        return p1;
    if(a[p2]<=a[p3])
        return p2;
    return p3;
}

void quicksort(std::vector<int>& a, int st, int dr) {
    while(st<dr) {
        int pivot_idx=median_of_three(a,st,dr);
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
    std::random_device rd;
    gen.seed(rd());
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
