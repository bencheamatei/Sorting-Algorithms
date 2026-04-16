#include "testlib.h"
#include <iostream>
#include <climits>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    std::cout << n << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << rnd.next(INT_MIN, INT_MAX);
        if (i<n-1) {
            std::cout << " ";
        }
    }
    std::cout << '\n';

    return 0;
}