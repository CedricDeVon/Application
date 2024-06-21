#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cout.tie(NULL);
    // std::cin.tie(NULL);

    double ga, gb, gc, gd,   ge, gf, gg, gh;
    std::cin >> ga >> gb >> gc >> gd >> ge >> gf >> gg >> gh;
    
    std::cout << (ga * ge + gb * gg) << ' ' << (ga * gf + gb * gh) << '\n';
    std::cout << (gc * ge + gd * gg) << ' ' << (gc * gf + gd * gh) << '\n';

    bool exitCode;
    std::cin >> exitCode;
}

/*
Name: Matrix 2x2 Inverse Validation
Type: Single-function
Naming: Minimalistic
Input Format:
4 7 
2 6   
0.6 -0.7
-0.2 0.4
Output Format:
1
Data Structures: None
Limits:
    Input Values: double
    Output Values: double
Workflow:
    optimization
    input matrices
    validate matrix
    display result
    handle exit code
*/