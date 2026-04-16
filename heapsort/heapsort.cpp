#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>

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

void heap_sort(vector<int>& a)
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    
    heap_sort(a);
    
    assert(is_sorted(a.begin(), a.end()));    
    
    
    return 0;
}