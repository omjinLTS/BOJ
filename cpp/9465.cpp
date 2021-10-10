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
int T, n;
pii dp[100001];
pii stickers[100001];
pii visited[100001];

int main() {
    fastio;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) cin >> stickers[i].X;
        for (int i = 1; i <= n; i++) cin >> stickers[i].Y;
        dp[0] = {0, 0};
        dp[1] = {stickers[1].X, stickers[1].Y};
        for (int i = 2; i <= n; i++) {
            dp[i] = {max(dp[i-2].Y, dp[i-1].Y)+stickers[i].X, max(dp[i-2].X, dp[i-1].X)+stickers[i].Y};
        }
        cout << max(dp[n].X, dp[n].Y) << '\n';
    }
    
    return 0;
}