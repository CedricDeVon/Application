#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    bool b[8][8];
    for (char i = 0; i < 8; i++)
    {
        for (char j = 0; j < 8; j++)
        {
            b[i][j] = (i + j) % 2;
        }
    }

    int n;
    std::cin >> n;
    while (n > -1)
    {
        std::string a;
        std::cin >> a;

        std::cout << ((b[a[0] - 'a']['8' - a[1]]) ? "Black" : "White") << " "; 
        n--;
    }
    std::cout << '\n';

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}
