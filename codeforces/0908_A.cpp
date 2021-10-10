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
#define sz(x) (int)x.size()
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

int t, n;
string s;

int main() {
    fastio;
    cin >> t;
    for (int i = 0; i < t; i++) {
        pii axis = {-1, -1};
        cin >> n >> s;
        bool balanced = false;
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                axis = {-1, -1};
                balanced = false;
                int c[2] = {0, 0};
                for (int idx = j; idx <= k; idx++) {
                    c[s[idx]-'a']++;
                }
                if (c[0] == c[1]) {
                    balanced = true;
                    axis = {j+1, k+1};
                    break;
                }
                if (balanced) break;
            }
            if (balanced) break;
        }
        cout << axis.X << ' ' << axis.Y << "\n";
    }
    
    
    return 0;
}