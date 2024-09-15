#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> p;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }

    for (auto sp : p)
    {
        cout << sp.first << " " << sp.second << endl;
    }

    return 0;
}