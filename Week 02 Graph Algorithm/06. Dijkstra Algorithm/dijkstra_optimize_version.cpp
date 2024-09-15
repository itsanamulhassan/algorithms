#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> v[N];
int distances[N];

void dijkstra(int src)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({src, 0});
    distances[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int weight = parent.second;

        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childWeight = child.second;

            int updateWeight = weight + childWeight;

            if (updateWeight < distances[childNode])
            {
                distances[childNode] = updateWeight;
                pq.push({childNode, updateWeight});
            }
        }
    }
};

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    while (edges--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 0; i < vertices; i++)
    {
        distances[i] = INT_MAX;
    }
    dijkstra(0);

    for (int i = 0; i < vertices; i++)
    {
        cout << i << "-> " << distances[i] << endl;
    }
    return 0;
}