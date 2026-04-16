#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <cmath>
#include <queue>
using namespace std;

void patience_sort(vector<int>& a)
{
    int n = a.size();
    if (n <= 1) return;

    vector<vector<int>> piles;
    vector<int> tops; 

    for (int x : a) {
        auto it = lower_bound(tops.begin(), tops.end(), x);
        if (it == tops.end()) {
            piles.push_back({x});
            tops.push_back(x);
        } else {
            int idx = it - tops.begin();
            piles[idx].push_back(x);
            tops[idx] = x;
        }
    }

    int k = piles.size();
    vector<int> pos(k); 

    for (int i = 0; i < k; ++i) {
        reverse(piles[i].begin(), piles[i].end());
        pos[i] = 0;
    }

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < k; ++i) {
        pq.push({piles[i][0], i});
    }

    int idx = 0;
    while (!pq.empty()) {
        auto [val, pi] = pq.top();
        pq.pop();
        a[idx++] = val;
        pos[pi]++;
        if (pos[pi] < (int)piles[pi].size()) {
            pq.push({piles[pi][pos[pi]], pi});
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
    
    patience_sort(a);
    
    assert(is_sorted(a.begin(), a.end()));    
    
    return 0;
}