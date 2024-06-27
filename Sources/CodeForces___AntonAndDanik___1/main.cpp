#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned int gva, gve;
    std::string gvb;
    std::cin >> gva >> gvb;
    gva = gve = 0;
    char* gvc = &gvb[0];
    const char* gvd = gvc + gvb.size();
    while (gvc < gvd)
    {
        if (*gvc == 'A')
        {
            ++gva;
        }
        else
        {
            ++gve;
        }
        ++gvc;
    }
    if (gva == gve)
    {
        std::cout << "Friendship";
    }
    else if (gva > gve)
    {
        std::cout << "Anton";
    }
    else if (gva < gve)
    {
        std::cout << "Danik";
    }

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}
