#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

double** createMatrix(int a, int b)
{
    double** c = (double**) calloc(a, sizeof(double*));
    while (a > -1)
    {
        c[a--] = (double*) calloc(b, sizeof(double));
    }
    return c;
}

void printMatrix(double** a, int b, int c)
{
    for (int ia = 0; ia < b; ++ia)
    {
        for (int ib = 0; ib < c; ++ib)
        {
            std::cout << a[ia][ib] << " ";
        }
        std::cout << '\n';
    }
}

void deleteMatrix(double** a, int b)
{
    while (b > -1)
    {
        free(a[b--]);
    }
    free(a);
}

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    unsigned int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    double** e = createMatrix(a, b);
    for (unsigned int i = 0; i < a; ++i)
    {
        for (unsigned int j = 0; j < b; ++j)
        {
            std::cin >> e[i][j];
        }
    }

    double** f = createMatrix(c, d);
    for (unsigned int i = 0; i < c; ++i)
    {
        for (unsigned int j = 0; j < d; ++j)
        {
            std::cin >> f[i][j];
        }
    }
    
    double** g = createMatrix(a, d);
    for (unsigned int i = 0; i < a; ++i)
    {
        for (unsigned int j = 0; j < d; ++j)
        {
            for (unsigned int k = 0; k < b; ++k)
            {
                g[i][j] += (e[i][k] * f[k][j]);
            }
        }
    }

    printMatrix(g, a, d);

    int exitCode;
    std::cin >> exitCode;
    return 0;
}
