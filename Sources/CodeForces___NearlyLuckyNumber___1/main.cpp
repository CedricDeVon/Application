#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string gvb;
    std::cin >> gvb;
    unsigned int gva = 0;
    char* gvc = &gvb[0], gve;
    const char* gvd = gvc + gvb.size();
    while (gvc < gvd)
    {   
        gve = *gvc;
        gva += (gve == '4' || gve == '7');
        ++gvc;
    }
    std::cout << ((gva == 4 || gva == 7) ? "YES" : "NO");

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}