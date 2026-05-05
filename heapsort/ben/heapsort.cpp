#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <chrono>

using namespace std;

void heapify(vector<int>& a, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max_idx = i;

    if (left < n && a[left] > a[max_idx])
        max_idx = left;

    if (right < n && a[right] > a[max_idx])
        max_idx = right;

    if (max_idx != i)
    {
        swap(a[i], a[max_idx]);
        heapify(a, n, max_idx);
    }
}

void buildMaxHeap(vector<int>& a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void custom_sort(vector<int>& a)
{
    buildMaxHeap(a);
    int n = a.size();
    
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]); 
        heapify(a, i, 0); 
    }
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