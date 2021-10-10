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
typedef long long int lli;
const int dx[]={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[]={ 0, 1, 0, -1, 1, 1, -1, -1 };
lli A, B;

lli bfs() {
    queue<pair<lli, lli>> q;// <현재 값, 연산 횟수>
    q.push({A, 0});
    while (!q.empty()) {
        lli n = q.front().X;
        lli cnt = q.front().Y;
        q.pop();
        if (n == B) return cnt;
        if (n*2 <= B) q.push({n*2, cnt+1});
        if (n*10 + 1 <= B) q.push({n*10+1, cnt+1});
    }
    return -2;
}

int main() {
    fastio;
    cin >> A >> B;
    cout << bfs() + 1;
    return 0;
}