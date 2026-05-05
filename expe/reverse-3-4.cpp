#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <random>
#include <chrono>

void custom_sort(std::vector<int> &v) {
    int n=(int)v.size();

    // practic pe mine ma avantajeaza cu cat vectorul e sortat mai descrescator 
    // daca vad ca e prea crescator atunci il randomizez 
    // o alta idee pe care o sa o incerc e sa-i dau efectiv reverse

    int cnt=0;
    for(int i=1; i<n; i++) {
        if(v[i]<v[i-1]) {
            ++cnt;
        }
    }

    if(4*cnt>=3*n) {
        std::reverse(v.begin(),v.end());
    }

    int* a=v.data();
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

    auto start=std::chrono::high_resolution_clock::now();
    custom_sort(a);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << "\n";
    assert(std::ranges::is_sorted(a));
    return 0;
}