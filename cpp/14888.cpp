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
int n, A[11], opers[4];
int minVal = 1e9, maxVal = -1e9;

void dfs(int result, int idx){
    if (idx == n){
        maxVal = max(maxVal, result);
        minVal = min(minVal, result);
        return;
    }
    for (int i = 0; i < 4; i++){
        if (opers[i]){
            opers[i]--;
            switch(i){
                case 0:
                   dfs(result + A[idx], idx+1);
                   break;
                case 1:
                   dfs(result - A[idx], idx+1);
                   break;
                case 2:
                   dfs(result * A[idx], idx+1);
                   break;
                case 3:
                   dfs(result / A[idx], idx+1);
                   break;
            }
            opers[i]++;
        }
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> opers[i];
    dfs(A[0], 1);
    cout << maxVal << '\n' << minVal;

    return 0;
}