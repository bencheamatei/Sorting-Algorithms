#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();

    // practic aici vreau sa scap de vector<vector>. cum anume pot sa fac asta? pun elementele liniar si pur 
    // si simplu marchez un element ca fiind top de stack si tin minte elementul previous din stack

    std::vector<int> tops,unde,prev(n,-1),els;

    for(int i=0; i<n; i++) {
        auto it=lower_bound(tops.begin(),tops.end(),a[i]);
        if(it==tops.end()) {
            tops.push_back(a[i]);
            unde.push_back(i);
        }
        else {
            int u=it-tops.begin();
            prev[i]=unde[u]; // aici pointez spre topul vechi
            tops[u]=a[i];
            unde[u]=i;
        }
    }

    std::priority_queue<std::pair<int,int>, 
        std::vector<std::pair<int,int> >, std::greater<std::pair<int,int> > > pq;

    for(const auto &it:unde) {
        pq.push({a[it],it});
    }

    while(!pq.empty()) {
        int val=pq.top().first;
        int pos=pq.top().second;
        pq.pop();
        els.push_back(val);
        if(prev[pos]!=-1) {
            pq.push({a[prev[pos]],prev[pos]});
        }
    }

    a=std::move(els);
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