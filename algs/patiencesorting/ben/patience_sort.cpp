#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ranges>
#include <cmath>
#include <queue>
#include <chrono>
using namespace std;

void custom_sort(vector<int>& a)
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