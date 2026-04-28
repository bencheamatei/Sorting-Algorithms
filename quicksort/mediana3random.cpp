#include <bits/stdc++.h>
using namespace std;

int median_of_three(vector<int>& a, int lo, int hi) {
    int p1=lo+rand()%(hi-lo+1),p2=lo+rand()%(hi-lo+1),p3=lo+rand()%(hi-lo+1);
    if(a[p1]>a[p3]) {
        swap(a[p1],a[p3]);
    }
    if(a[p2]<=a[p1])
        return p1;
    if(a[p2]<=a[p3])
        return p2;
    return p3;
}

void quicksort(vector<int>& a, int lo, int hi) {
    while (lo < hi) {
        int pivotIdx = median_of_three(a, lo, hi);
        swap(a[pivotIdx], a[hi]);
        int pivot = a[hi];

        int i = lo - 1, j = hi;
        while (true) {
            while (a[++i] < pivot);
            while (j > lo && a[--j] > pivot);
            if (i >= j) break;
            swap(a[i], a[j]);
        }
        swap(a[i], a[hi]);

        if (i - lo < hi - i) {
            quicksort(a, lo, i - 1);
            lo = i + 1;
        } else {
            quicksort(a, i + 1, hi);
            hi = i - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
