#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> num;
    int i, j, sum = 0;
    int end = 0;

    for (i = 0; i < 9; i++)
    {
        int n;
        cin >> n;
        num.push_back(n);
        sum += n;
    }
    for (i = 0; i < 8; i++)
    {
        for (j = i+1; j < 9; j++)
		{
            if (sum - num[i] - num[j] == 100)
			{
				end = 1;
				break;
			}
		}
        if (end)
        	break;
    }
	num.erase(num.begin()+i);
	num.erase(num.begin()+j-1);
    
    for (int x : num) cout << x << "\n";
    
    return 0;
}
