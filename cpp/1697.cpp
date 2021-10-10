#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[]={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[]={ 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    int board[100001] = {0,};
    queue<int> q;

    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            break;
        }
        int nx[3] = {x-1, x+1, x*2};
        for (int i = 0; i < 3; i++) {
            if (nx[i] < 0 || nx[i] > 100000 || board[nx[i]]) continue;
            q.push(nx[i]);
            board[nx[i]] = board[x] + 1;
        }
    }
    cout << board[k];
    return 0;
}