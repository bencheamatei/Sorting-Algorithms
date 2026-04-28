#include <bits/stdc++.h>
using namespace std;

std::mt19937 gen;
int get_nr(int left, int right)
{
    std::uniform_int_distribution<> distrib(left, right);
    return distrib(gen);
}

int median_of_three(vector<int>& a, int lo, int hi) {
    int p1=get_nr(lo,hi),p2=get_nr(lo,hi),p3=get_nr(lo,hi);
    if(a[p1]>a[p3]) {
        swap(a[p1],a[p3]);
    }
    if(a[p2]<=a[p1])
        return p1;
    if(a[p2]<=a[p3])
        return p2;
    return p3;
}

void quicksort(vector<int>& a, int st, int dr) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::random_device rd;
    gen.seed(rd());

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    quicksort(a, 0, (int)a.size() - 1);

    assert(is_sorted(a.begin(), a.end()));    
    return 0;
}
