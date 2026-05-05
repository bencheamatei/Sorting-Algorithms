#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <bit>
#include <chrono>

int Mediana3(const std::vector<int>& v, int a, int b, int c)
{
    if (v[a] < v[b])
    {
        if (v[b] < v[c]) return b;
        if (v[a] < v[c]) return c;
        return a;
    }
    else
    {
        if (v[a] < v[c]) return a;
        if (v[b] < v[c]) return c;
        return b;
    }
}

int Partitie_Hoare(std::vector<int>& v, int st, int dr)
{
    int mij = st + ((dr - st) >> 1);
    int pivot = v[Mediana3(v, st, mij, dr)];
    int i = st - 1;
    int j = dr + 1;
    while (true)
    {
        do
        {
            ++i;
        } while (v[i] < pivot);
        do
        {
            --j;
        } while (v[j] > pivot);

        if (i >= j) return j;
        std::swap(v[i], v[j]);
    }
}

void InsertionSort(std::vector<int>& v, int st, int dr)
{
    for (int i = st + 1; i <= dr; ++i)
    {
        int x = v[i];
        int j = i - 1;
        while (j >= st && v[j] > x)
        {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = x;
    }
}

void IntroSortRec(std::vector<int>& v, int st, int dr, int adancime)
{
    const int limita = 16;
    while(dr - st + 1 > limita)
    {
        if (std::is_sorted(v.begin() + st, v.begin() + dr + 1)) return;
        if(adancime == 0)
        {
            std::make_heap(v.begin() + st, v.begin() + dr + 1);
            std::sort_heap(v.begin() + st, v.begin() + dr + 1);
            return;
        }
        --adancime;
        int p = Partitie_Hoare(v, st, dr);
        if (p - st < dr - (p + 1))
        {
            IntroSortRec(v, st, p, adancime);
            st = p + 1;
        }
        else
        {
            IntroSortRec(v, p + 1, dr, adancime);
            dr = p;
        }
    }
}

void custom_sort(std::vector<int>& v)
{
    if (v.size() < 2) return;
    int depthLimit = 2 * (std::bit_width(v.size()) - 1);
    IntroSortRec(v, 0, (int)v.size() - 1, depthLimit);
    InsertionSort(v, 0, (int)v.size() - 1);
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