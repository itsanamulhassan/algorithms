#include <bits/stdc++.h>
using namespace std;

bool bfs(int n)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        if (current == n)
        {
            return true;
        }

        int multiply = current * 2, addition = current + 3;

        if (multiply <= n && !visited[multiply])
        {
            q.push(multiply);
            visited[multiply] = true;
        }
        if (addition <= n && !visited[addition])
        {
            q.push(addition);
            visited[addition] = true;
        }
    }
    return false;
}

int main()
{
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int n;
        cin >> n;

        if (!bfs(n))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}