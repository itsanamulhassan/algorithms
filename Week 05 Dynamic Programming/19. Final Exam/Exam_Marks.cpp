#include <bits/stdc++.h>
using namespace std;

int n, m, marks[1000];
bool dp[1001];

bool perfect_score(int required_marks)
{
    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = required_marks; j >= marks[i]; j--)
        {
            dp[j] = dp[j] || dp[j - marks[i]];
        }
    }

    return dp[required_marks];
}

int main()
{
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            cin >> marks[i];
        }

        int required_marks = 1000 - m;
        if (required_marks < 0)
        {

            cout << "NO" << endl;
        }
        else if (required_marks == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            memset(dp, false, sizeof(dp));
            if (perfect_score(required_marks))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}