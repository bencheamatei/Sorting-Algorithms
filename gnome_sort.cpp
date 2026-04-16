#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void gnome_sort(vector<int>& a)
{
    int n = a.size() - 1;
    int pos = 0;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    
    gnome_sort(a);
    
    assert(is_sorted(a.begin(), a.end()));    
    
    return 0;
}