#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> picked;
vector<int> selected;
set<int> s = 0;


void DFS(int Cnt, int n)
{
    if (Cnt == 0) selected.resize(n, 0);
    if (Cnt == n)
    {
        if (n)
            picked.emplace_back(selected);
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        selected[Cnt] = i;
        DFS(Cnt + 1, n);
    }
}


int solution(vector<vector<int>> dice) {
    vector<int> nums;
    for (int i = 0; i < dice.size(); i++) {
        sort(dice[i].begin(), dice[i].end());
        DFS(0, i+1);
    }
    
    for (int i = 0; )

    for (int i = 0; i < picked.size(); i++) {
        for (int j = 0; j < picked[i].size(); j++) cout << picked[i][j];
        cout << "\n";
        int n = dice[0][picked[i][0]];
        if (n == 0) continue;
        for (int j = 1; j < picked[i].size(); j++) {
            n*=10;
            n+= dice[j][picked[i][j]];
        }
        nums.emplace_back(n);
    }

    int s = nums[0];
    int i = 0;
    while(++i < nums.size() && ++s == nums[i]) {
        continue;
    }
    
    return s;
}

int main() {
    cout << solution({{1, 6, 2, 5, 3, 4},{9, 9, 1, 0, 7, 8}});
}