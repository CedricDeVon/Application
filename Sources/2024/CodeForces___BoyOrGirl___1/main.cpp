#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string inputs;
    std::cin >> inputs;

    int count = 0;
    std::unordered_set<char> seenCharacters;
    for (char c : inputs)
    {
        if (seenCharacters.find(c) != seenCharacters.end())
        {
            continue;
        }

        seenCharacters.insert(c);
        count++;
    }

    std::cout << ((count % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!") << '\n';
 
    return 0;
}