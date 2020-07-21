#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, ind;
    pair<int, int> cnt;
    cnt = make_pair(0, 0);
    cin >> a >> b >> c;

    vector<int> d_sum;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                d_sum.push_back(i+j+k);
            }
        }
    }

    sort(d_sum.begin(), d_sum.end());

    for(int i = 1; i < d_sum.size(); i++)
    {
        if (d_sum[i]==d_sum[i-1] && i != d_sum.size() -1)
            cnt.second++;
        else if (cnt.second > cnt.first)
        {
            cnt.first = cnt.second;
            cnt.second = 0;
            ind = i-1;
        }
        else
        {
            cnt.second = 0;
        }
        
    }

    cout << d_sum[ind];

    return 0;
}