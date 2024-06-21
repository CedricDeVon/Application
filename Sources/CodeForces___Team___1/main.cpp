#include <iostream>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, count = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        bool a, b, c;
        std::cin >> a >> b >> c;
        count += (a + b + c) > 1;
    }
    std::cout << count << '\n';

    return 0;
}