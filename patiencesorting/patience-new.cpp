#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();
    std::vector<int> tops,idx;
    std::vector<int> pos(n,-1),aux(n);

    for(int i=0; i<n; i++) {
        auto it=lower_bound(tops.begin(),tops.end(),a[i]);
        if(it==tops.end()) {
            tops.push_back(a[i]);
            idx.push_back(i);
        }
        else {
            int u=it-tops.begin();
            tops[u]=a[i];
            idx[u]=i;
            pos[i]=idx[u];
        }
    }

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int> >,
                        std::greater<std::pair<int,int> > > pq;

    for(int x:idx) {
        pq.push({a[x],x});
    }

    int cnt=0,val,unde;
    while(!pq.empty()) {
        val=pq.top().first;
        unde=pq.top().second;
        pq.pop();

        aux[cnt++]=val;
        if(pos[unde]>=0) {
            pq.push({a[pos[unde]],pos[unde]});
        }
    }
    a=std::move(aux);
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