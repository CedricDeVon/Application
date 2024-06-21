#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

constexpr unsigned long long int ceilingDivision(
    unsigned long long int x,
    unsigned long long int y)
{
    return static_cast<unsigned long long int>(std::ceil((double) x / y));
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    unsigned long long int n, m, a;
    std::cin >> n >> m >> a;
    std::cout << ceilingDivision(n, a) * ceilingDivision(m, a) << '\n';

    // int exitCode;
    // std::cin >> exitCode;
    return 0;
}
