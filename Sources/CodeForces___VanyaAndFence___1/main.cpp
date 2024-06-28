#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int gva, gvb, gvc, gvd = 0;
    std::cin >> gva >> gvb;
    while (gva > 0)
    {
        std::cin >> gvc;
        gvd += (gvc > gvb) ? 2 : 1;
        --gva;
    }
    std::cout << gvd;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}
