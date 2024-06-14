#include <bits/stdc++.h>

#include "../CodeProfiler/codeProfilerSetup.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    int** m;
    int* pa, *pb;
    CodeProfiler* profiler = new CodeProfiler("LoopTests", 100, 10000, 100);
    profiler->recordRunningTime("V1",
    [&m, &pa, &pb](unsigned long long int n) -> void {
        while (pa < pb)
        {
            *pa++ = 0;
        }
        pa = *m;
        while (pa < pb)
        {
            *pa++ = 2;
        }
    },
    [&m, &pa, &pb](unsigned long long int n) -> void {
        m = new int*[n];
        for (unsigned long long int i = 0; i < n; ++i)
        {
            m[i] = new int[n];
        }
        pa = *m;
        pb = *(m + n) + n + 1;
    },
    [&m](unsigned long long int n) -> void {
        for (unsigned long long int i = 0; i < n; ++i)
        {
            free(m[i]);
        }
        free(m);
    });
    profiler->recordRunningTime("V2",
    [&m](unsigned long long int n) -> void {
        for (unsigned long long int i = 0; i < n; ++i)
        {
            for (unsigned long long int j = 0; j < n; ++j)
            {
                m[i][j] = 0;
            }
            for (unsigned long long int j = 0; j < n; ++j)
            {
                m[i][j] = 2;
            }  
        }
    },
    [&m](unsigned long long int n) -> void {
        m = new int*[n];
        for (unsigned long long int i = 0; i < n; ++i)
        {
            m[i] = new int[n];
        }
    },
    [&m](unsigned long long int n) -> void {
        for (unsigned long long int i = 0; i < n; ++i)
        {
            free(m[i]);
        }
        free(m);
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
