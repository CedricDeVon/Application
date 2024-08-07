#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    long long int a, b = 0, c = 1;
    std::cin >> a;
    while (a > 0)
    {
        b += (c % 2 == 0) ? +c : -c;
        ++c;
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
