#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define X first
#define Y second
#define pb push_back
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

typedef enum {lparen, rparen, pls, mns, times, divide, mod, eos, operand} precedence;
string s;
stack<int> stk;

precedence getPre(char c) {
    switch (c){
        case '(': return lparen;
        case ')': return rparen;
        case '+': return pls;
        case '-': return mns;
        case '/': return divide;
        case '*': return times;
        default: return operand;
    }
}
int inStackPre[8] = {0, 3, 1, 1, 2, 2, 2, 0};
int incominPre[8] = {4, 3, 1, 1, 2, 2, 2, 0};

int main() {
    fastio;
    cin >> s;
    
    for (int i = 0; i < (int)s.size(); i++){
        precedence type = getPre(s[i]);
        if (type == operand) cout << (char)s[i];
        else if (type == rparen) {
            while (getPre(stk.top()) != lparen){
                cout << (char)stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            while (!stk.empty() && inStackPre[getPre(stk.top())] >= incominPre[type]){
                cout << (char)stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.empty()){
        cout << (char)stk.top();
        stk.pop();
    }
    return 0;
}