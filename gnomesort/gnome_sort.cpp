#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void custom_sort(vector<int>& a)
{
    int n = a.size();
    int pos = 1;
    while(pos<n)
    {
        if (pos == 0 || a[pos] >= a[pos-1])
        {
            pos++;
        }
        else{
            swap(a[pos], a[pos-1]);
            pos --;
        }
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