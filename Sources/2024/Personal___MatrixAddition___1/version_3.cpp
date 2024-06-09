#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<int>> d(b, vector<int>(c));
    int aa = a * b * c;
    for (int g = 0; g < aa; ++g)
    {
        int value;
        cin >> value;
        int index = g % c;
        d[g / c][index] += value;
    }

    for (const auto& row : d) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << '\n';
    }

    return 0;
}