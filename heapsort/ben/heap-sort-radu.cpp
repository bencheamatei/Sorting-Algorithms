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

void custom_sort(vector<int>& a) {
    int n = a.size();
    for( int i = n/2 - 1; i >= 0; i-- )
        heappify(a, n, i);
    for( int i = n-1; i > 0; i-- ){
        swap(a[i], a[0]);
        heappify(a, i, 0);
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