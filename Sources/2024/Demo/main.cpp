#include <bits/stdc++.h>

#include "../Miscellaneous/runningTimeProfiler.cpp"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // std::cout << "(25 & 12) : " << (25 & 12) << '\n';
    // std::cout << "(25 | 12) : " << (25 | 12) << '\n';
    // std::cout << "(25 ^ 12) " << (25 ^ 12) << '\n';
    // std::cout << "~(35) : " << ~(35) << '\n';
    // std::cout << "(212 >> n) : " << (212 >> 0) << ", " << (212 >> 1) << ", " << (212 >> 2) << '\n';
    // std::cout << "(212 << n) : " << (212 << 0) << ", " << (212 << 1) << ", " << (212 << 2) << '\n';

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}

    // RunningTimeProfiler runningTimeProfiler(1, 1, 1000);
    // runningTimeProfiler.execute("preDecrement.csv", [](const unsigned long long int &n) -> void
    // {
    //     unsigned long long int a = n;
    //     while (a > 0)
    //     {
    //         --a;
    //     }
    // });
    // runningTimeProfiler.execute("postDecrement.csv", [](const unsigned long long int &n) -> void
    // {
    //     unsigned long long int a = n;
    //     while (a > 0)
    //     {
    //         a--;
    //     }
    // });