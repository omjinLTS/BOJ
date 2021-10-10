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

using namespace std;
typedef long long ll;
const int dx[]={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[]={ 0, 1, 0, -1, 1, 1, -1, -1 };

int par[2000001], uRank[2000001];
int cnt[2000001];

int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

int merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return cnt[b];
    if (uRank[a] > uRank[b]) swap(a, b);
    par[a] = b;
    cnt[b] = cnt[a] + cnt[b];
    if (uRank[a] == uRank[b]) uRank[b]++;
    return cnt[b];
}


int main() {
    fastio;
    int T;
    cin >> T;
    while(T--) {
        int F;
        cin >> F;
        for (int i = 1; i <= 2*F; i++) {
            par[i] = i;
            uRank[i] = 1;
            cnt[i] = 1;
        }
        map<string, int> relation;
        int n = 1;
        while (F--) {
            string a, b;
            cin >> a >> b;
            if (!relation.count(a)) relation[a] = n++;
            if (!relation.count(b)) relation[b] = n++;
            cout << merge(relation[a], relation[b]) << "\n";
        }
    }
    return 0;
}