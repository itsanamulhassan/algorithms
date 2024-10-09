#include <bits/stdc++.h>
using namespace std;

bool can_equal_divided(const vector<int> &numbers, int target_sum)
{
    int n = numbers.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target_sum + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < target_sum; i++)
    {
        dp[0][i + 1] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target_sum; j++)
        {
            if (numbers[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - numbers[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target_sum];
}

int main()
{
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> numbers(n);
        for (int j = 0; j < n; j++)
        {
            cin >> numbers[j];
            sum += numbers[j];
        }
        if (sum % 2 == 0)
        {
            int target_sum = sum / 2;
            if (can_equal_divided(numbers, target_sum))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}