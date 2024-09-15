#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> distances(101, vector<int>(101, -1));

vector<pair<int, int>> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int minimum_steps_count(int N, int M, int Ki, int Kj, int Q, int Qj)
{
    if (Ki == Q && Kj == Qj)
    {
        return 0;
    }
    else
    {
        queue<pair<int, int>> q;

        q.push({Ki, Kj});
        distances[Ki][Kj] = 0;

        while (!q.empty())
        {
            pair<int, int> current = q.front();
            int direction_x = current.first;
            int direction_y = current.second;
            q.pop();
            for (pair<int, int> direction : directions)
            {
                int new_direction_x = direction_x + direction.first;
                int new_direction_y = direction_y + direction.second;

                if (new_direction_x < N && new_direction_x >= 0 && new_direction_y >= 0 && new_direction_y < M && distances[new_direction_x][new_direction_y] == -1)
                {
                    distances[new_direction_x][new_direction_y] = distances[direction_x][direction_y] + 1;

                    if (new_direction_x == Q && new_direction_y == Qj)
                    {
                        return distances[new_direction_x][new_direction_y];
                    }

                    q.push({new_direction_x, new_direction_y});
                }
            }
        }
        return -1;
    }
}

int main()
{
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        int N, M;
        cin >> N >> M;

        int Ki, Kj;
        cin >> Ki >> Kj;

        int Qi, Qj;
        cin >> Qi >> Qj;

        for (int j = 0; j < 101; j++)
        {
            for (int k = 0; k < 101; k++)
            {
                distances[j][k] = -1;
            }
        }

        cout << minimum_steps_count(N, M, Ki, Kj, Qi, Qj) << endl;
    }

    return 0;
}