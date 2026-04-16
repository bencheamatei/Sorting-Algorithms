#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <cmath>
#include <queue>
using namespace std;

void bubble_sort(vector<int>& a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
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
    
    bubble_sort(a);
    
    assert(is_sorted(a.begin(), a.end()));    
    
    return 0;
}