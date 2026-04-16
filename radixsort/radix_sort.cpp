#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <cmath>
#include <queue>
using namespace std;

void radix_sort(vector<int>& a)
{
    int n = a.size();
    if (n <= 1) return;

    vector<int> neg, pos;
    for (int x : a) {
        if (x < 0) neg.push_back(-x); 
        else        pos.push_back(x);
    }

    auto radix_sort_nonneg = [](vector<int>& v) {
        int n = v.size();
        if (n <= 1) return;
        vector<int> tmp(n);
        for (int shift = 0; shift < 32; shift += 8) {
            int count[256] = {};
            for (int x : v) count[(x >> shift) & 0xFF]++;
            // Prefix sums
            for (int i = 1; i < 256; ++i) count[i] += count[i - 1];
            // Stable placement (iterate in reverse)
            for (int i = n - 1; i >= 0; --i) {
                int bucket = (v[i] >> shift) & 0xFF;
                tmp[--count[bucket]] = v[i];
            }
            swap(v, tmp);
        }
    };

    radix_sort_nonneg(pos);
    radix_sort_nonneg(neg);

    int idx = 0;
    for (int i = (int)neg.size() - 1; i >= 0; --i)
        a[idx++] = -neg[i];
    for (int x : pos)
        a[idx++] = x;
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
    
    radix_sort(a);
    
    assert(is_sorted(a.begin(), a.end()));    
    
    return 0;
}