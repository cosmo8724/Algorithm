/* 23. 08. 15 */
#include <bits/stdc++.h>

using namespace std;

int N, ret = numeric_limits<int>::max();
vector<int> need;
vector<vector<int>> food;
map<int, vector<vector<int>>> mp;

int main()
{
	cin >> N;
	for (int i = 0; i < 4; i++) {
		int elem;
		cin >> elem;
		need.push_back(elem);
	}
	for (int i = 0; i < N; i++) {
		food.push_back(vector<int>());
		for (int j = 0; j < 5; j++) {
			int elem;
			cin >> elem;
			food[i].push_back(elem);
		}
	}
	
	for (int i = 0; i < (1 << N); i++) {
		vector<int> cur(5, 0);
		vector<int> v;

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				v.push_back(j + 1);
				cur[0] += food[j][0];
				cur[1] += food[j][1];
				cur[2] += food[j][2];
				cur[3] += food[j][3];
				cur[4] += food[j][4];
			}
		}

		if (cur[0] >= need[0] && cur[1] >= need[1] && cur[2] >= need[2] && cur[3] >= need[3] && ret >= cur[4]) {
			ret = cur[4];
			mp[ret].push_back(v);
		}
	}
	
	if (mp[ret].empty()) { cout << -1; }
	else {
		sort(mp[ret].begin(), mp[ret].end());
		cout << ret << '\n';
		for (int i : mp[ret][0]) {
			cout << i << ' ';
		}
	}

	return 0;
}