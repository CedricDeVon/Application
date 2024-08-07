#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned short int a, b;
    std::cin >> a;
    while (a > 0)
    {
        std::cin >> b;
        if (b == 1)
        {
            break;
        }
        --a;
    }
    std::cout << ((a > 0) ? "HARD" : "EASY");

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}