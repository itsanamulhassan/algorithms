#include <bits/stdc++.h>

using namespace std;

const int CONST_N = 101;
vector<vector<long long int>> distances(101, vector<long long int>(CONST_N, -1));

void floyd(int vertices)
{
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            for (int k = 1; k <= vertices; k++)
            {
                if (distances[i][k] < 1e18 && distances[j][i] < 1e18)
                {
                    distances[j][k] = min(distances[j][k], distances[i][k] + distances[j][i]);
                }
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i + 1 == j + 1)
            {
                distances[i + 1][j + 1] = 0;
            }
            else
            {
                distances[i + 1][j + 1] = 1e18;
            }
        }
    }

    for (int i = 0; i < edges; i++)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        distances[a][b] = min(distances[a][b], c);
    }

    floyd(vertices);

    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {

        int X, Y;
        cin >> X >> Y;
        if (distances[X][Y] != 1e18)
        {
            cout << distances[X][Y] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}