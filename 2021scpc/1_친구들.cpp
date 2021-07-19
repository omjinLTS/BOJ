/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Answer;

int find(vector<pair<int, int>> pairs, pair<int, int> p) {
	for(int i = 0; i < pairs.size(); i++) {
		if (pairs[i].first == p.first || pairs[i].first == p.second || pairs[i].second == p.first || pairs[i].second == p.second) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int N;

		Answer = 0;
		cin >> N;

        vector<pair<int, int>> pairs;
        for(int i = 1; i <= N; i++){
			int tmp;
            cin >> tmp;
			pairs.push_back(make_pair(i, i + tmp));
        }

		sort(pairs.begin(), pairs.end());

		while(pairs.size()) {
			Answer++;
			pair<int, int> tmp = pairs[0];
			pairs.erase(pairs.begin());
			while (int i = find(pairs, tmp) > 0) {
				tmp = pairs[i];
				pairs.erase(pairs.begin() + i);
			}
		}

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

