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
#define MAX 10001
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

int N, M, k, A[MAX], par[MAX], uRank[MAX];

int find(int a) {
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a==b) return;
    if (A[a] < A[b]) par[b] = a;
    else par[a] = b;
}

int main() {
    fastio;

    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        par[i] = i;
        uRank[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    int money = 0;
    for (int i = 1; i <= N; i++) {
        if (par[i] == i)
        money += A[i];
    }
    if (money <= k) {
        cout << money;
    } else {
        cout << "Oh no";
    }
    
    return 0;
}