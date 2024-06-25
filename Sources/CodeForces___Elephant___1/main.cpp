#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int gva, gvb = 0;
    std::cin >> gva;
    while (gva > 0)
    {
        gva -= 5;
        ++gvb;
    }
    std::cout << gvb;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}