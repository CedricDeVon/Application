#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int gva;
    std::string gvb;
    std::cin >> gva >> gva >> gvb;
    char *gvc = &gvb[0], *gve, *gvf;
    const char* gvg = gvc + gvb.size() - 1;
    while (gva > 0)
    {
        gve = gvc;
        while (gve < gvg)
        {
            gvf = gve + 1;
            if (*gve == 'B' && *gvf == 'G')
            {
                *gve = 'G';
                *gvf = 'B';
                ++gve;
            }
            ++gve;
        }
        --gva;
    }
    std::cout << gvb;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}