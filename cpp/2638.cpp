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
int board[100][100];
int air[100][100];
int visited[100][100];
int n, m;

void checkAir() {
    memset(visited, 0, sizeof(visited));
    memset(air, 0, sizeof(air));
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty()) {
        int y = q.front().X;
        int x = q.front().Y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (board[ny][nx]) air[ny][nx]++;
            else if (!visited[ny][nx]) {
                visited[ny][nx]++;
                q.push({ny, nx});
            }
        }
    }
}

bool meltCheeze() {
    bool melted = false;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if (air[y][x] > 1) {board[y][x]--; melted = true;}
    return melted;
}

int main() {
    fastio;
    cin >> n >> m;
    int cnt  = 0;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++) cin >> board[y][x];
    while (1) {
        checkAir();
        bool melted = meltCheeze();
        if (melted) cnt++;
        else break;
    }
    cout << cnt;
    return 0;
}