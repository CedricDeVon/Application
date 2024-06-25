#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned int gva;
    std::string gvb;
    std::cin >> gva >> gvb;
    char* gvd = &gvb[0], *gvf = gvd + 1;
    const char* gve = gvd + gva;
    gva = 0;
    while (gvd < gve)
    {
        if (*gvd == *gvf)
        {
            ++gva;
        }
        ++gvd;
        ++gvf;
    }
    std::cout << gva;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}