#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();

    std::vector<std::vector<int> > heaps;
    std::vector<int> tops;

    heaps.push_back({a[0]});
    tops.push_back(a[0]);

    for(int i=1; i<n; i++) {
        auto it=lower_bound(tops.begin(),tops.end(),a[i]);
        if(it==tops.end()) {
            heaps.push_back({a[i]});
            tops.push_back(a[i]);
        }
        else {
            int u=it-tops.begin();
            heaps[u].push_back(a[i]);
            tops[u]=a[i];
        }
    }

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int> >,
                        std::greater<std::pair<int,int> > > pq;

    for(int i=0; i<(int)heaps.size(); i++) {
        pq.push({heaps[i].back(),i});
    }
    
    int pos=0;
    while(!pq.empty()) {
        a[pos++]=pq.top().first;
        int pp=pq.top().second;
        pq.pop();

        heaps[pp].pop_back();
        if(!heaps[pp].empty()) {
            pq.push({heaps[pp].back(),pp});
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