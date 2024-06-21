#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int** initializeMatrix(int s)
{
    int** m = new int*[s];
    for (int i = 0; i < s; i++)
    {
        m[i] = new int[s];
        for (int j = 0; j < s; j++)
        {
            m[i][j] = (i == j) ? 0 : ((rand() % 2) ? -INFINITY : rand() % 101);
        }
    }

    return m;
}

void deleteMatrix(int** m, int s)
{
    for (int i = 0; i < s; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}

void printMatrix(int** m, int s)
{
    std::ostringstream oss;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            oss << m[i][j] << " ";
        }
        oss << '\n';
    }
    std::cout << oss.str() << '\n';
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    srand(time(NULL));

    int s;
    std::cin >> s;
    int** m = initializeMatrix(s);
    printMatrix(m, s);
    deleteMatrix(m, s);

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}