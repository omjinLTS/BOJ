#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define X first
#define Y second
#define pb push_back
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
int N;
int dp[11];

int main() {
    fastio;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> N;
        for (int j = 4; j <= N; j++) dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        cout << dp[N] << '\n';
    }
    
    return 0;
}