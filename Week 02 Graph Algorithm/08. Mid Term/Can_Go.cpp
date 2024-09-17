#include <bits/stdc++.h>
using namespace std;
const int CONST_N = 1005;
vector<pair<int, int>> grid[1001];
vector<long int> distances(CONST_N, INT_MAX);

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    distances[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        int src = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (distance > distances[src])
        {
            continue;
        }

        for (pair<int, int> edge : grid[src])
        {
            int value = edge.first;
            int weight = edge.second;

            long int update_weight = distances[src] + weight;

            if (update_weight < distances[value])
            {
                distances[value] = update_weight;
                pq.push({distances[value], value});
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({b, c});
    }

    int src;
    cin >> src;

    dijkstra(src);

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        int distance, distance_weight;
        cin >> distance >> distance_weight;

        if (distances[distance] <= distance_weight)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}