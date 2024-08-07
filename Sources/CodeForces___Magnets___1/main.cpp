#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    unsigned int a, b = 1, c, d;

    std::cin >> a;
    if (a == 1)
    {
        std::cin >> c;
        std::cout << "1";
        return;
    }
    std::cin >> c;
    while (a > 1)
    {
        std::cin >> d;
        b += (c != d);
        c = d;
        --a;
    }
    std::cout << b;
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
