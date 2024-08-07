#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    unsigned int a, b = 0, c, d;
    std::cin >> a;

    while (a > 0)
    {
        std::cin >> c >> d;
        b += ((d - c) > 1);
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
