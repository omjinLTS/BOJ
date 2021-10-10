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

int par[20001], dist[20001] = {0};

int find(int a) {
    if (par[a] == a) return a;
    dist[a] += dist[par[a]];
    return par[a] = find(par[a]);
}

void merge(int i, int j) {
    par[i] = j;
    dist[i] = abs(i-j)%1000;
}

int main() {
    fastio;
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            dist[i] = 0;
        }
        while (1) {
            char inst;
            cin >> inst;
            if (inst == 'E') {
                int a;
                cin >> a;
                find(a);
                cout << dist[a] << "\n";
            } else if (inst == 'I') {
                int a, b;
                cin >> a >> b;
                merge(a, b);
            } else break;
        }
    }
    
    return 0;
}