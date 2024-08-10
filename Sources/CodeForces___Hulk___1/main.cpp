#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    bool b = true;
    unsigned short int a;
    std::cin >> a;
    
    std::cout << "I hate" << ((a == 1) ? " it" : "");
    while (--a > 0)
    {
        if (b)
        {
            std::cout << " that I love it";
        }
        else
        {
            std::cout << " that I hate it";
        }
        b = !b;
    }
}



int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solution();

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}