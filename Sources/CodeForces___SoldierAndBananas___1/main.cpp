#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int gva, gvb, gvc, gvd = 0;
    std::cin >> gva >> gvb >> gvc;

    while (gvc > 0)
    {
        gvd += gvc-- * gva;
    }
    gvb -= gvd;
    
    std::cout << ((gvb < 0) ? -gvb : 0);

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}