#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    int va, vb;
    std::cin >> va >> vb;

    double vc[va][vb];
    for (int vd = va - 1; vd > -1; --vd)
    {
        for (int ve = 0; ve < vb; ++ve)
        {
            std::cin >> vc[vd][ve];
        }
    }
    std::string a;
    for (int vd = 0; vd < va; ++vd)
    {
        for (int ve = 0; ve < vb; ++ve)
        {
            a += std::to_string(vc[vd][ve]) + ' ';
        }
        a += '\n';
    }
    std::cout << a;
    
    bool exitCode;
    std::cin >> exitCode;
    return 0;
}