#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    unsigned int a, c, d = 0;
    std::cin >> a;
    unsigned int b[a];
    while (d < a)
    {
        std::cin >> c;
        b[c - 1] = d++;
    }
    while (a < d)
    {
        std::cout << b[a++] << ' ';
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