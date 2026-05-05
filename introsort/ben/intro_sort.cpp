#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <cmath>
#include <chrono>
using namespace std;

void insertion_sort(vector<int>& a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= lo && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

void sift_down(vector<int>& a, int lo, int hi, int i) {
        while (true) {
        int largest = i;
        int left = 2 * (i - lo) + 1 + lo;
        int right = 2 * (i - lo) + 2 + lo;
        if (left <= hi && a[left] > a[largest]) largest = left;
        if (right <= hi && a[right] > a[largest]) largest = right;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapsort_range(vector<int>& a, int lo, int hi) {
    int n = hi - lo + 1;
    for (int i = lo + n / 2 - 1; i >= lo; --i)
        sift_down(a, lo, hi, i);
    for (int i = hi; i > lo; --i) {
        swap(a[lo], a[i]);
        sift_down(a, lo, i - 1, lo);
    }
}

int median_of_three(vector<int>& a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[lo] > a[mid]) swap(a[lo], a[mid]);
    if (a[lo] > a[hi]) swap(a[lo], a[hi]);
    if (a[mid] > a[hi]) swap(a[mid], a[hi]);
    return mid;
}

void intro_sort(vector<int>& a, int lo, int hi, int depth_limit)
{
     while (hi - lo + 1 > 16) {
        if (depth_limit == 0) {
            heapsort_range(a, lo, hi);
            return;
        }
        --depth_limit;

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

void custom_sort(vector<int>& a)
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

    auto start=std::chrono::high_resolution_clock::now();
    custom_sort(a);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << "\n";
    assert(std::ranges::is_sorted(a));
    return 0;
}