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
vector<string> dict;
string board[8];
bool visited[8][8];
int W, D;

bool dfs(int x, int y, string s) {
    if (board[x][y] != s[0] || visited[x][y]) return false;
    if (sz(s) == 1) return true;
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= D || ny >= D) continue;
        if (dfs(nx, ny, s.substr(1))) return true;
    }
    visited[x][y] = false;
    return false;
}

bool hasWord(string s) {
    for (int x = 0; x < D; x++)
        for (int y = 0; y < D; y++){
            memset(visited, false, sizeof(visited));
            if (dfs(x, y, s)) return true;
        }
    return false;
}

int main() {
    fastio;
    cin >> W;
    
    
    for (int i = 0; i < W; i++){
        int possible = true;
        string tmp;
        string::size_type pos;
        cin >> tmp;
        for (int j = 0; j < sz(tmp)-1; j++) {
            if (tmp[j] == 'q' && tmp[j+1] != 'u'){
                possible = false;
                break;
            }
        }
        if (tmp[sz(tmp)-1] == 'q') possible = false;
        if (possible) {
            while ((pos = tmp.find("qu")) != std::string::npos) tmp.replace(pos, 2, "q");
            dict.eb(tmp);
        }
    }
    sort(dict.begin(), dict.end());

    cin >> D;
    while (D) {
        for (int i = 0; i < D; i++) {
            cin >> board[i];
        }
        for (int i = 0; i < sz(dict); i++){ 
            if (hasWord(dict[i])) {
                for (int j = 0; j < sz(dict[i]); j++) {
                    if (dict[i][j] == 'q') cout << "qu";
                    else cout << dict[i][j];
                }
                cout << "\n";
            }
        }
        cout << "-\n";
        cin >> D;
    }
    return 0;
}