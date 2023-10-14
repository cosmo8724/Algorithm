/* 23. 08. 17 */
#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<vector<int>> mp[2];

int go(const vector<vector<int>>& _case)
{
	int ret = 0, cnt = 1;

	for (int i = 0; i < N; i++) {
		bool flag = true;
		cnt = 1;

		for (int j = 0; j < N - 1; j++) {
			if (_case[i][j] == _case[i][j + 1]) { cnt++; }
			else if (_case[i][j] + 1 == _case[i][j + 1] && cnt >= L) { cnt = 1; }
			else if (_case[i][j] - 1 == _case[i][j + 1] && cnt >= 0) { cnt = -L + 1; }
			else { flag = false; break; }
		}

		if (flag && cnt >= 0) { ret++; }
	}

	return ret;
}

int main()
{
	cin >> N >> L;
	vector<vector<int>>(N, vector<int>(N, 0)).swap(mp[0]);
	vector<vector<int>>(N, vector<int>(N, 0)).swap(mp[1]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[0][i][j];
			mp[1][j][i] = mp[0][i][j];
		}
	}

	cout << go(mp[0]) + go(mp[1]) << '\n';

	return 0;
}