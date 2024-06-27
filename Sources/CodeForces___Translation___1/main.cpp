#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string gva, gvb;
    std::cin >> gva >> gvb;
    if (gva.size() != gvb.size())
    {
        std::cout << "NO";
        return 0;
    }
    
    char* gvc = &gva[0], *gve = &gvb[0] + gvb.size() - 1;
    const char* gvd = gvc + gva.size();
    while (gvc < gvd)
    {
        if (*gvc != *gve)
        {
            break;
        }
        ++gvc;
        --gve;
    }
    std::cout << ((gvc == gvd) ? "YES" : "NO");

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}