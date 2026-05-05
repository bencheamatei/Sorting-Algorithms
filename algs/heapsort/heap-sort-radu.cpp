#include <bits/stdc++.h>
using namespace std;

void heappify( vector <int>& h, int n, int i ){
    int big = i;
    int left = i * 2 + 1, right = i * 2 + 2;
    if( left < n && h[left] > h[big] )
        big = left;
    if( right < n && h[right] > h[big] )
        big = right;
    if( big != i ){
        swap(h[i], h[big]);
        heappify(h, n, big);
    }
}

void heapsort(vector<int>& a) {
    int n = a.size();
    for( int i = n/2 - 1; i >= 0; i-- )
        heappify(a, n, i);
    for( int i = n-1; i > 0; i-- ){
        swap(a[i], a[0]);
        heappify(a, i, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for( int& x : a) cin >> x;

    heapsort(a);
    assert(ranges::is_sorted(a));
    return 0;
}