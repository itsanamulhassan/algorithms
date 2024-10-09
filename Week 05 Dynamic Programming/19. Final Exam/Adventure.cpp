#include <bits/stdc++.h>
using namespace std;

int items, weights;
int knap_sack(int weight[], int value[])
{
    int dp[items + 1][weights + 1];
    for (int i = 0; i <= items; i++)
    {
        for (int j = 0; j <= weights; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[items][weights];
}

int main()
{
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> items >> weights;

        int weight[items], value[items];

        for (int i = 0; i < items; i++)
        {
            cin >> weight[i];
        }

        for (int i = 0; i < items; i++)
        {
            cin >> value[i];
        }

        cout << knap_sack(weight, value) << endl;
    }

    return 0;
}