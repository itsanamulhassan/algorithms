#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> mat[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    for (int i = 0; i < mat[3].size(); i++)
    {

        cout << mat[3][i] << " ";
    }

    // if (mat[3][1])
    // {
    //     cout << "Connection available" << endl;
    // }
    // else
    // {
    //     cout << "Connection not available" << endl;
    // }

    return 0;
}