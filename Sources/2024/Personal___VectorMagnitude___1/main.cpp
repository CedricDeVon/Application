#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC taget("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    double ga, gb, gc, gd;
    std::cin >> ga >> gb >> gc >> gd;
    std::cout << sqrt((gc - ga) * (gc - ga) + (gd - gb) * (gd - gb));

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}
