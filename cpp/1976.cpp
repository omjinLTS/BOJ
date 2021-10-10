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

int N, M;
int par[201], uRank[201];

int find(int a) {
    if(a == par[a]) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (uRank[a] > uRank[b]) swap(a, b);
    par[a] = b;
    if (uRank[a] == uRank[b]) uRank[b]++;
}

int main() {
    fastio;
    cin >> N >> M;
    //init 
    for (int i = 1; i <= N; i++) par[i]=i, uRank[i]=1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) merge(i, j);
        }
    }
    int root;
    cin >> root;
    root = finr(root);
    for (int i = 1; i < M; i++) {
        int tmp;
        cin >> tmp;
        if (root != find(tmp)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}