#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    const unsigned int ga = 2;
    double gb[ga][ga];
    double gc, gd;
    for (unsigned int ia = 0; ia < ga; ++ia)
    {
        for (unsigned int ib = 0; ib < ga; ++ib)
        {
            std::cin >> gb[ia][ib];
        }   
    }
    gc = 1 / (gb[0][0] * gb[1][1] - gb[0][1] * gb[1][0]);
    gd = gb[0][0];
    gb[0][0] = gb[1][1] * gc;
    gb[1][1] = gd * gc;

    gb[0][1] = -gb[0][1] * gc; 
    gb[1][0] = -gb[1][0] * gc;

    for (unsigned int ia = 0; ia < ga; ++ia)
    {
        for (unsigned int ib = 0; ib < ga; ++ib)
        {
            std::cout << gb[ia][ib] << ' ';
        }
        std::cout << '\n';
    }

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}