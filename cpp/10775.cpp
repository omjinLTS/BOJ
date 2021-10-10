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

int par[100001], gate[100001] = {0}, G, P;

int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (a < b) swap(a, b);
    par[a] = b;
}

int main() {
    fastio;
    cin >> G >> P;
    int i;
    for (i = 1; i <= G; i++) par[i] = i;
    for (i = 0; i <= P; i++) {
        int g;
        cin >> g;
        if (find(g) == 0) break;
        gate[find(g)] = 1;
        merge(find(g), find(g)-1);
    }
    cout << i;
    return 0;
}