#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned int gva, gvb, gvc = 0;
    std::cin >> gva >> gvb;
    while (gva <= gvb)
    {
        gva *= 3;
        gvb *= 2;
        ++gvc;
    }
    std::cout << gvc;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}