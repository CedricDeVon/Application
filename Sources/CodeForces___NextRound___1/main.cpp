#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    short n, k, b = 0, c = 0;
    std::cin >> n >> k;
    --k;
    short a[n];
    short *cpa = a - 1, *cpb = a + n, *pa = cpa, *pb = cpb;
    while (++pa < pb)
    {
        std::cin >> *pa;
    }
    b = a[k] - 1;
    b = (b == -1) ? 0 : b;
    pa = cpa;
    while (++pa < pb)
    {
        if (*pa > b) { ++c; }
    }
    std::cout << c << '\n';
    // bool exitCode;
    // std::cin >> exitCode;
    return 0;
}

