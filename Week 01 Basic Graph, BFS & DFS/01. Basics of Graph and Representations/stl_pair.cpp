#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int first, second;
    // void make_pair(int first, int second)
    // {
    //     this->first = first;
    //     this->second = second;
    // }

    Pair(int first, int second)
    {
        this->first = first;
        this->second = second;
    }
};

int main()
{
    // Pair p(10, 20);
    // p.first = 10;
    // p.second = 20;
    // p.make_pair(10, 20);

    pair<int, int> p;
    // p.first = 10;
    // p.second = 20;
    p = make_pair(10, 20);

    cout
        << p.first << " " << p.second << endl;

    return 0;
}