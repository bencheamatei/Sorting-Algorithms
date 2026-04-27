#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>

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

void sift_down(std::vector<int>& a, int lo, int hi, int i) {
        while (true) {
        int largest = i;
        int left = 2 * (i - lo) + 1 + lo;
        int right = 2 * (i - lo) + 2 + lo;
        if (left <= hi && a[left] > a[largest]) largest = left;
        if (right <= hi && a[right] > a[largest]) largest = right;
        if (largest == i) break;
        std::swap(a[i], a[largest]);
        i = largest;
    }
}

void heapsort_range(std::vector<int>& a, int lo, int hi) {
    int n = hi - lo + 1;
    for (int i = lo + n / 2 - 1; i >= lo; --i)
        sift_down(a, lo, hi, i);
    for (int i = hi; i > lo; --i) {
        std::swap(a[lo], a[i]);
        sift_down(a, lo, i - 1, lo);
    }
}

int median_of_three(std::vector<int>& a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[lo] > a[mid]) std::swap(a[lo], a[mid]);
    if (a[lo] > a[hi]) std::swap(a[lo], a[hi]);
    if (a[mid] > a[hi]) std::swap(a[mid], a[hi]);
    return mid;
}

void intro_sort(std::vector<int>& a, int lo, int hi, int depth_limit)
{
     while (hi - lo + 1 > 16) {
        if (depth_limit == 0) {
            heapsort_range(a, lo, hi);
            return;
        }
        --depth_limit;

        int pivotIdx = median_of_three(a, lo, hi);
        std::swap(a[pivotIdx], a[hi]);
        int pivot = a[hi];

        int i = lo - 1, j = hi;
        while (true) {
            while (a[++i] < pivot);
            while (j > lo && a[--j] > pivot);
            if (i >= j) break;
            std::swap(a[i], a[j]);
        }
        std::swap(a[i], a[hi]);

        // Recurse on smaller partition, iterate on larger
        if (i - lo < hi - i) {
            intro_sort(a, lo, i - 1, depth_limit);
            lo = i + 1;
        } else {
            intro_sort(a, i + 1, hi, depth_limit);
            hi = i - 1;
        }
    }
    insertion_sort(a, lo, hi);
}

void custom_sort(std::vector<int>& a)
{
    int n = a.size();
    if (n <= 1) return;
    int depth_limit = 2 * (int)log2(n);
    intro_sort(a, 0, n - 1, depth_limit);
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