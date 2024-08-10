#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solution()
{
    unsigned int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << ((a == b || a == c) + (b == c || b == d) + (c == d || d == a));
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