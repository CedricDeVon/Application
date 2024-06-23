#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string A;
    std::unordered_map<char, short> B;
    std::cin >> A;
    char* pa = &A[0] - 1;
    const char* pb = pa + A.size() + 1;
    while (++pa < pb)
    {
        ++B[*pa];
    }
    pa = &A[0] - 2;
    short a = B['1'], b = B['2'], c = B['3'];
    while (--a > -1)
    {
        *++++pa = '1';
    }
    while (--b > -1)
    {
        *++++pa = '2';
    }
    while (--c > -1)
    {
        *++++pa = '3';
    }
    std::cout << A << '\n';

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}