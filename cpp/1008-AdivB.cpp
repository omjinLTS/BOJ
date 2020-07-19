#include <iostream>
using namespace std;

int main()
{
	long double a, b;

    // 입출력 속도 늘리기
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    cout.precision(100);
    cout << a/b;
    return 0;
} 
