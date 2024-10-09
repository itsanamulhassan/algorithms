#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int n;
        cin >> n;
        int a[n];
        vector<pair<int, int>> lines;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            lines.push_back({i, a[i]});
        }
        sort(lines.begin(), lines.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });

        if (lines[0].first > lines[1].first)
        {
            cout << lines[1].first << " " << lines[0].first << endl;
        }
        else
        {
            cout << lines[0].first << " " << lines[1].first << endl;
        }
    }
    return 0;
}