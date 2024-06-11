#include <bits/stdc++.h>

#include "../CodeProfiler/codeProfilerSetup.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    // std::string a;

    CodeProfilerSettings* settings = new CodeProfilerSettings("A", 0, 1000, 1);
    CodeProfiler* profiler = new CodeProfiler(settings);
    profiler->recordRunningTime("a",
    [](unsigned long long int n) -> void {

    });
    profiler->recordRunningTime("b",
    [](unsigned long long int n) -> void {

    });
    profiler->visualizeResults();

    // std::cout << std::filesystem::current_path().string() << '\n';

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
