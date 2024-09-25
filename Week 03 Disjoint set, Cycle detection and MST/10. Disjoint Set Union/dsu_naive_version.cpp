#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
    parent[1] = 3;
    parent[2] = 1;
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    return dsu_find(parent[node]);
}
int main()
{

    dsu_initialize(4);

    cout << dsu_find(0) << endl;
    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;

    return 0;
}