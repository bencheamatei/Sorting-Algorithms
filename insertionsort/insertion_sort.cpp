#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void insertion_sort(vector<int>& a)
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    
    insertion_sort(a);
    
    assert(is_sorted(a.begin(), a.end()));    
    
    return 0;
}