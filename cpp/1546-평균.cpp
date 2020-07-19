#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<double> scores;
    int m, n;
    double s_sum = 0;
    cin >> n;
    m = n;
    
    while(m--)
    {
        int a;
        cin >> a ;
        scores.push_back(a);
    }
    sort(scores.begin(), scores.end());
    for(int i = 0; i < scores.size(); i++)
    {
        scores[i] = scores[i] / scores.back() * 100;
        s_sum += scores[i];
    }

    cout << s_sum/n;

    return 0;
}