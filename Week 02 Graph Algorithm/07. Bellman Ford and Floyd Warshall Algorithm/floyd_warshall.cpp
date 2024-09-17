#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    long long int adj[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INT_MAX;
            }
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    // cout << "---> Before" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adj[i][j] == INT_MAX)
    //         {
    //             cout << "INF" << " ";
    //         }
    //         else
    //         {
    //             cout << adj[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    // cout << "---> After" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adj[i][j] == INT_MAX)
    //         {
    //             cout << "INF" << " ";
    //         }
    //         else
    //         {
    //             cout << adj[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // CYCLE DETECTED

    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] < 0)
        {
            cout << "Graph contains a negative-weight cycle" << endl;
            break;
        }
    }

    return 0;
}