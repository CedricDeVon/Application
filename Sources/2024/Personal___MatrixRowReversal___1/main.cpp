#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    unsigned int a, b;
    std::cin >> a >> b;
    double c[a][b];
    double* pa, *pb;
    std::string outputStream;
    for (unsigned int ia = 0; ia < a; ++ia)
    {
        pb = *(c + ia) - 1;
        pa = pb + b;
        while (pa > pb)
        {
            std::cin >> *pa--;
        }
        pa++;
        pb = pa + b;
        while (pa < pb)
        {
            outputStream += std::to_string(*pa++) + " ";
        }
        outputStream += '\n';
    }
    std::cout << outputStream;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}
