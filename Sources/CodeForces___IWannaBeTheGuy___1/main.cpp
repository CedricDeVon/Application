#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    unsigned short int a, b, d;
    std::cin >> a >> b;
    std::unordered_set<unsigned short int> c;
    while (b > 0)
    {
        std::cin >> d;
        c.insert(d);
        --b;
    }
    std::cin >> b;
    while (b > 0)
    {
        std::cin >> d;
        c.insert(d);
        --b;
    }
    std::cout << ((a == c.size()) ? "I become the guy." : "Oh, my keyboard!");
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
