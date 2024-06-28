#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int gva;
    std::cin >> gva;
    std::unordered_set<int> gvb;
    while (gva < 2100)
    {
        ++gva; 
        gvb.clear();
        gvb.insert(gva % 10);
        if (gvb.contains(gva / 10 % 10))
        {
            continue;
        }
        gvb.insert(gva / 10 % 10);
        if (gvb.contains(gva / 100 % 10))
        {
            continue;
        }
        gvb.insert(gva / 100 % 10);
        if (gvb.contains(gva / 1000 % 10))
        {
            continue;
        }
        break;
    }
    std::cout << gva;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}