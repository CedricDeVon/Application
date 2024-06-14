#include <bits/stdc++.h>

#include "../CodeProfiler/codeProfilerSetup.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    CodeProfiler* profiler = new CodeProfiler("DisplayTesting", 10, 1000, 10);
    profiler->recordRunningTime("Dynamic_Pointer_Arithmetic",
    [](unsigned long long int n) -> void {

    },
    [](unsigned long long int n) -> void {

    },
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

// #define _GLIBCXX_USE_NANOSLEEP
// #include <iostream>
// #include <string>
// #include <thread>

// void callback(const std::string& data)
// {
//     std::cout << "Callback called because: " << data << '\n';
// }

// void task(int time, const std::string& message)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(time));
//     callback(message);
// }

// std::cout << "async task launched\n";
// std::this_thread::sleep_for(std::chrono::seconds(3));
// std::thread ba(task, 2, "Async Message 1");
// std::thread bb(task, 1, "Async Message 2");
// std::cout << "main done\n";
// ba.join();
// bb.join();
