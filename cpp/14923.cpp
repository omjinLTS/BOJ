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
int board[1001][1001];
int visited[1001][1001][2] = {0, };
int N, M, Hy, Hx, Ey, Ex;

int bfs() {
    queue<pair<pii, int>> q;
    q.push({{Hy, Hx}, 1});
    visited[Hy][Hx][1] = 0;
    while(!q.empty()) {
        int y = q.front().X.X;
        int x = q.front().X.Y;
        int breakable = q.front().Y;
        q.pop();

        if (y == Ey && x == Ex) return visited[y][x][breakable];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
            if (board[ny][nx] && breakable) {
                visited[ny][nx][breakable-1] = visited[y][x][breakable] + 1;
                q.push({{ny, nx}, 0});
            }
            if (!board[ny][nx] && !visited[ny][nx][breakable]) {
                visited[ny][nx][breakable] = visited[y][x][breakable] + 1;
                q.push({{ny, nx}, breakable});
            }
        }
    }
    return -1;
}

int main() {
    fastio;
    cin >> N >> M >> Hy >> Hx >> Ey >> Ex;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) cin >> board[y][x];
    }
    
    cout << bfs();
    return 0;
}