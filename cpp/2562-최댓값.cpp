#include <iostream>
using namespace std;

int main()
{
    int m = 0, m_idx = 0;

    for(int i = 1; i <= 9; i++)
    {
        int a;
        cin >> a;
        if ( a > m )
        {
            m = a;
            m_idx = i;
        }
    }
    cout << m << "\n" << m_idx;

    return 0;
}