#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    double a;
    unsigned int b, c;
    std::cin >> a >> b >> c;

    double d[b][c];
    double* pa = *d, *pb = b * c + *d;
    while (pa < pb)
    {
        scanf("%lf", pa);
        *pa++ *= a;
    }

    pa = *d;
    std::ostringstream os;
    for (unsigned int ia = 0; ia < b; ++ia)
    {
        for (unsigned int ib = 0; ib < c; ++ib)
        {
            os << *pa++ << ' ';
        }
        os << '\n';
    }
    std::cout << os.str();

    int exitCode;
    std::cin >> exitCode;
    return 0;
}