#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <cassert>
#include <chrono>

void custom_sort(std::vector<int> &a) {
    int n=(int)a.size();

    std::vector<int> aux(n);
    int cnt[4][256]={0};

    for(int i=0; i<n; i++) {
        unsigned int x=(unsigned int)a[i];
        cnt[0][x&0xFF]++;
        cnt[1][(x>>8)&0xFF]++;
        cnt[2][(x>>16)&0xFF]++;
        cnt[3][(x>>24)^(1<<7)]++;
    }

    for(int i=0; i<4; i++) {
        int s=0;
        for(int j=0; j<256; j++) {
            int u=cnt[i][j];
            cnt[i][j]=s;
            s+=u;
        }
    }

    for(int i=0; i<n; i++) {
        unsigned int x=(unsigned int)a[i];
        int unde=x&0xFF;
        aux[cnt[0][unde]++]=a[i];
    }

    for (int i=0; i<n; i++) {
        unsigned int x=(unsigned int)aux[i];
        int unde=(x>>8)&0xFF;
        a[cnt[1][unde]++]=aux[i];
    }

    for (int i=0; i<n; i++) {
        unsigned int x=(unsigned int)a[i];
        int unde=(x>>16)&0xFF;
        aux[cnt[2][unde]++]=a[i];
    }

    for (int i=0; i<n; i++) {
        unsigned int x=(unsigned int)aux[i];
        int unde=(x>>24)^128;
        a[cnt[3][unde]++]=aux[i];
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