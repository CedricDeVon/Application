#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int gva, gvb;
    std::cin >> gva >> gvb;

    while (gvb > 0)
    {
        gva = (gva % 10 > 0) ? gva - 1 : gva / 10;
        --gvb;
    }
    std::cout << gva;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}