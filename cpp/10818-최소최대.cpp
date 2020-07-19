#include <iostream>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    pair<int, int> p;
       

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!i)
            p = pair<int, int>(a, a); 
        else
        {
            if (a < p.first) p.first = a;
            if (a > p.second) p.second = a;
        }
    }

    cout << p.first << " " << p.second;
}