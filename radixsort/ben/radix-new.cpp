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

    int* src=a.data();
    int* dest=aux.data();

    for(int i=0; i<n; i++) {
        unsigned int x=(unsigned int)src[i];
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
        unsigned int x=(unsigned int)src[i];
        int unde=x&0xFF;
        dest[cnt[0][unde]++]=src[i];
    }

    for (int i=0; i<n; i++) {
        unsigned int x=(unsigned int)dest[i];
        int unde=(x>>8)&0xFF;
        src[cnt[1][unde]++]=dest[i];
    }

    for (int i=0; i<n; i++) {
        unsigned int x=(unsigned int)src[i];
        int unde=(x>>16)&0xFF;
        dest[cnt[2][unde]++]=src[i];
    }

    for (int i=0; i<n; i++) {
        unsigned int x=(unsigned int)dest[i];
        int unde=(x>>24)^128;
        src[cnt[3][unde]++]=dest[i];
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