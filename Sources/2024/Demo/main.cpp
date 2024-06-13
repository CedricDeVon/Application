#include <bits/stdc++.h>

#include "../CodeProfiler/codeProfilerSetup.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    CodeProfiler* profiler = new CodeProfiler("A", 0, 1000, 10);
    profiler->recordRunningTime("Version 1",
    [](unsigned long long int n) -> void {

    });
    profiler->recordRunningTime("Version 2",
    [](unsigned long long int n) -> void {

    });
    profiler->recordRunningTime("Version 3",
    [](unsigned long long int n) -> void {

    });
    profiler->visualizeResults();

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}

// std::cout << "(25 & 12) : " << (25 & 12) << '\n';
// std::cout << "(25 | 12) : " << (25 | 12) << '\n';
// std::cout << "(25 ^ 12) " << (25 ^ 12) << '\n';
// std::cout << "~(35) : " << ~(35) << '\n';
// std::cout << "(212 >> n) : " << (212 >> 0) << ", " << (212 >> 1) << ", " << (212 >> 2) << '\n';
// std::cout << "(212 << n) : " << (212 << 0) << ", " << (212 << 1) << ", " << (212 << 2) << '\n';
