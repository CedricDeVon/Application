#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string a, b, f = "0";
    std::cin >> a >> b;
    char* pa = &a[0] - 1, *pb = &b[0] - 1;
    const char *pc = pa + a.size();
    while (pa < pc)
    {
        char d = *++pa, e = *++pb;
        d = (d < 'a') ? d - 'A' + 'a' : d;
        e = (e < 'a') ? e - 'A' + 'a' : e;
        if (d < e)
        {
            f = "-1";
            break;
        }
        else if (d > e)
        {
            f = "1";
            break;
        }
    }
    std::cout << f;
    // bool exitCode;
    // std::cin >> exitCode;
    return 0;
}