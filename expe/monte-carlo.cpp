#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <random>
#include <chrono>

// std::mt19937 gen;
// int get_nr(int left, int right)
// {
//     std::uniform_int_distribution<> distrib(left, right);
//     return distrib(gen);
// }

uint32_t state=7916266;

inline uint32_t fast_rand() {
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

inline uint32_t fast_range(uint32_t N) {
    return (uint32_t)(((uint64_t)fast_rand() * (uint64_t)N) >> 32);
}

int monte_carlo(const std::vector<int> &v,int sz) {
    int ans=0;
    for(int i=0; i<1000; i++) {
        int st=fast_range(sz);
        int dr=fast_range(sz);
        if(st>dr)
            std::swap(st,dr);

        if(v[st]>v[dr])
            ans++;
    }
    return ans;
}

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();

    if(monte_carlo(a,n)<50) {
        std::reverse(a.begin(),a.end());
    }

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