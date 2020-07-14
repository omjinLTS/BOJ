#include <iostream>
using namespace std;

int main()
{
    int a, ord, cnt = 0;

    cin >> a;
    ord = a;
    do
    {
        if (a < 10)
            a = a * 10 + a;
        else
            a = a % 10 * 10 + (a / 10 + a % 10)%10;
        cnt += 1;
    }while(a != ord);

    cout << cnt;
}