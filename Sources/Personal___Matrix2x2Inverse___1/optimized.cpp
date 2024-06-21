#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    double a, b, c, d, e;
    std::cin >> d >> b >> c >> a;
    e = 1 / (d * a - b * c);
    std::cout << (a * e) << ' ' << (-b * e) << '\n' << (-c * e) << ' ' << (d * e);

    // bool exitCode;
    // std::cin >> exitCode;
    return 0;
}