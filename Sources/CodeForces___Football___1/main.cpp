#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    bool gvh;
    int gva = 0;
    std::string gvc;
    std::cin >> gvc;
    char* gvd = &gvc[0], *gve = gvd + gvc.size(), gvf = *gvd, gvg;
    while (gvd < gve)
    {
        gvg = *gvd;
        gvh = gvg == gvf;
        if (!gvh)
        {            
            gvf = gvg;
        }
        gva = (gvh) ? gva + 1 : 1;
        if (gva == 7)
        {
            break;
        }
        ++gvd;
    }
    std::cout << ((gva == 7) ? "YES" : "NO");

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}