#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <cmath>
#include <queue>
using namespace std;

void custom_sort(vector<int>& a)
{
    int* v=a.data();
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                int tmp=v[j+1];
                v[j+1]=v[j];
                v[j]=tmp;
                swapped = true;
            }
        }
        if (!swapped) break; 
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

    custom_sort(a);
    assert(std::ranges::is_sorted(a));
    return 0;
}