#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    int a;
    double c, d, e = 0;
    std::cin >> a;
    c = a * 100;
    while (a > 0)
    {
        std::cin >> d;
        e += d;
        --a;
    }
    std::cout << static_cast<double>(e / c * 100) << '\n';
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