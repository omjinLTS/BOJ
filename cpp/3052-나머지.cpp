#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> p;
    
    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        if (i == 0)
        {
            p.push_back(n%42);
        }
        else
        {
            if(find(p.begin(), p.end(), n%42)== p.end())
            {
                p.push_back(n%42);
            }
        }
    }
    cout << p.size();
    
    return 0;
}