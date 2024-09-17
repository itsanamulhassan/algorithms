#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    long long int u, v, w;
    Edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<Edge> my_edges;
long long int distances[1001];

bool flag = false;

void bellman_ford(int src, int vertices)
{
    distances[src] = 0;

    for (int i = 1; i < vertices; i++)
    {
        for (Edge edge : my_edges)
        {
            long long int update_distance = distances[edge.u] + edge.w;
            if (update_distance < distances[edge.v] && distances[edge.u] != 1e18)
            {
                distances[edge.v] = update_distance;
            }
        }
    }

    for (Edge edge : my_edges)
    {
        long long int update_distance = distances[edge.u] + edge.w;
        if (update_distance < distances[edge.v] && distances[edge.u] != 1e18)
        {
            flag = true;
            break;
        }
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++)
    {
        long long int x, y, z;
        cin >> x >> y >> z;
        my_edges.push_back({x, y, z});
    }

    int src;
    cin >> src;

    for (int i = 1; i <= vertices; i++)
    {
        distances[i] = 1e18;
    }

    bellman_ford(src, vertices);

    int test_cases;
    cin >> test_cases;

    if (!flag)
    {
        for (int i = 0; i < test_cases; i++)
        {
            int distance;
            cin >> distance;
            if (1e18 != distances[distance])
            {
                cout << distances[distance] << endl;
            }
            else
            {
                cout << "Not Possible" << endl;
            }
        }
    }
    else
    {
        cout << "Negative Cycle Detected" << endl;
    }

    return 0;
}