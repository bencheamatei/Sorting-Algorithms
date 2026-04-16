#include <bits/stdc++.h>
using namespace std;

int median_of_three(vector<int>& a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[lo] > a[mid]) swap(a[lo], a[mid]);
    if (a[lo] > a[hi]) swap(a[lo], a[hi]);
    if (a[mid] > a[hi]) swap(a[mid], a[hi]);
    return mid;
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
