#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void custom_sort(vector<int>& a)
{
    int n = a.size();
    for(int i = 1; i<n;i++)
    {
        int j = i;
        while (j>0 && a[j-1] > a[j])
        {
            swap(a[j],a[j-1]);
            j = j - 1;
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