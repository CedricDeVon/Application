#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int gva, gvb, gvc = 0, gvd = 0;
    std::cin >> gva;
    while (gva > -1)
    {
        std::cin >> gvb;
        gvc -= gvb;
        std::cin >> gvb;
        gvc += gvb;
        if (gvc > gvd)
        {
            gvd = gvc;
        }
        --gva;
    }
    std::cout << gvd;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}