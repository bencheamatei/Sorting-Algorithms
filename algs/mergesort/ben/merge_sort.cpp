#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <chrono>

using namespace std;

void merge(vector<int>& a, vector<int>& tmp, int lo, int mid, int hi){
    for (int i = lo; i<=hi;i++) tmp[i] = a[i];
    int i = lo, j = mid + 1, k = lo;
    while(i <= mid && j<=hi)
    {
        if(tmp[i] <= tmp[j]) a[k++] = tmp[i++];
        else a[k++] = tmp[j++];
    }
    while (i <= mid) a[k++] = tmp[i++];
    while (j <= hi)  a[k++] = tmp[j++];
}

void merge_sort(vector<int>& a, vector<int>& tmp, int lo, int hi)
{
    if(lo>=hi) return;
    int mid = lo + (hi - lo)/2;
    merge_sort(a, tmp, lo, mid);
    merge_sort(a, tmp, mid + 1, hi);
    merge(a, tmp, lo, mid, hi);
}

void custom_sort(vector<int>& a)
{
    int n = a.size();
    if (n <= 1) return;
    vector<int> tmp(n);
    merge_sort(a, tmp, 0, n - 1);
    
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
