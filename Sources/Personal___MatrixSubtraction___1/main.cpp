#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int** createMatrix(int a, int b)
{
    int** c = new int*[a];
    for (int d = 0; d < a; ++d)
    {
        c[d] = new int[b];
        for (int e = 0; e < b; ++e)
        {
            c[d][e] = 0;
        }
    }
    return c;
}

void deleteMatrix(int** a, int b)
{
    --b;
    while (b > -1)
    {
        delete[] a[b--];
    }
    delete[] a;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a, b, c;
    std::cin >> a >> b >> c;

    int** d = createMatrix(a, b);
    int l = a * b * c;
    for (int e = 0; e < l; ++e)
    {
        int k;
        std::cin >> k;
        d[e / c][e % c] += k;
    }

    deleteMatrix(d, b);

    int exitCode;
    std::cin >> exitCode;
    return 0;
}
