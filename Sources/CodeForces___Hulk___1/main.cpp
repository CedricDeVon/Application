#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    bool b = true;
    unsigned short int a;
    std::cin >> a;
    
    std::cout << "I hate";
    if (a == 1)
    {
        std::cout << " it";
        return;
    }

    while (--a > 0)
    {
        std::cout << ((b) ? " that I love" : " that I hate");
        b = !b;
    }
    std::cout << " it";
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