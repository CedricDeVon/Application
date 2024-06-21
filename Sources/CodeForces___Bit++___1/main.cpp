#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, a = 0;
    std::string s;
    std::cin >> n;
    while (n > 0)
    {
        std::cin >> s;
        (s[1] == '+') ? a++ : a--;
        n--;
    }
    std::cout << a;

    // int exitCode;
    // std::cin >> exitCode;

    return 0;
}