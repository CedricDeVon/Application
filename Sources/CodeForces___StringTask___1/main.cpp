#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string gva, gvb;
    std::unordered_map<char, char> gvf
    {
        {'A', ' '},
        {'a', ' '},
        {'B', 'b'},
        {'b', 'b'},
        {'C', 'c'},
        {'c', 'c'},
        {'D', 'd'},
        {'d', 'd'},
        {'E', ' '},
        {'e', ' '},
        {'F', 'f'},
        {'f', 'f'},
        {'G', 'g'},
        {'g', 'g'},
        {'H', 'h'},
        {'h', 'h'},
        {'I', ' '},
        {'i', ' '},
        {'J', 'j'},
        {'j', 'j'},
        {'K', 'k'},
        {'k', 'k'},
        {'L', 'l'},
        {'l', 'l'},
        {'M', 'm'},
        {'m', 'm'},
        {'N', 'n'},
        {'n', 'n'},
        {'O', ' '},
        {'o', ' '},
        {'P', 'p'},
        {'p', 'p'},
        {'Q', 'q'},
        {'q', 'q'},
        {'R', 'r'},
        {'r', 'r'},
        {'S', 's'},
        {'s', 's'},
        {'T', 't'},
        {'t', 't'},
        {'U', ' '},
        {'u', ' '},
        {'V', 'v'},
        {'v', 'v'},
        {'W', 'w'},
        {'w', 'w'},
        {'X', 'x'},
        {'x', 'x'},
        {'Y', ' '},
        {'y', ' '},
        {'Z', 'z'},
        {'z', 'z'}
    };

    std::cin >> gva;
    char* gvd = &gva[0] - 1;
    const char* gve = gvd + gva.size() + 1;
    while (++gvd < gve)
    {
        char lva = gvf[*gvd];
        if (lva == ' ')
        {
            continue;
        }

        gvb += ".";
        gvb += lva;
    }
    std::cout << gvb;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}