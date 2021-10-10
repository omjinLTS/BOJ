#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l+r)>>1)
//for fileio, ERASE BEFORE SUBMIT
#define cin in
#define cout out
std::ifstream in("../input.txt");
std::ofstream out("../output.txt");
//*******************************

using namespace std;
typedef long long ll;
const int dx[]={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[]={ 0, 1, 0, -1, 1, 1, -1, -1 };
int n;
int a[100001];
int dp[100001] = {0,};

int main() {
    fastio;
    cin >> n;
    int maxVal = -1000;
    for (int i = 1; i <= n; i++) {cin >> a[i]; dp[i] = a[i];}
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i-1]+a[i]);
        maxVal = max(dp[i], maxVal);
    }
    cout << maxVal;
    return 0;
}