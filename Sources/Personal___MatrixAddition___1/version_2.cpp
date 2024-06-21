#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a, b, c;
    std::cin >> a >> b >> c;

    int d[b][c];
    for (int g = 0; g < a; ++g)
    {
        for (int h = 0; h < b; ++h)
        {
            for (int i = 0; i < c; ++i)
            {
                int j;
                std::cin >> j;
                d[h][i] = (g == 0) ? j : d[h][i] + j;
            }   
        }
    }

    for (int k = 0; k < b; ++k)
    {
        for (int l = 0; l < c; ++l)
        {
            std::cout << d[k][l] << " ";
        }
        std::cout << '\n';
    }

    // int exitCode;
    // std::cin >> exitCode;
    return 0;
}