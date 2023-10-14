/* 23. 09. 04 */
#include <bits/stdc++.h>

using namespace std;

int N, ret{ numeric_limits<int>::max() };
vector<vector<int>> v;
vector<int> teamStart, teamLink;

int CalcDeff()
{
	int sumStart = 0;
	int sumLink = 0;

	for (int i{ 0 }; i < N / 2; ++i) {
		for (int j{ 0 }; j < N / 2; ++j) {
			if (i == j) { continue; }
			sumStart += v[teamStart[i]][teamStart[j]];
			sumLink += v[teamLink[i]][teamLink[j]];
		}
	}

	return abs(sumStart - sumLink);
}

int main()
{
	cin >> N;
	vector<vector<int>>(N, vector<int>(N, 0)).swap(v);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			cin >> v[i][j];
		}
	}

	for (unsigned int i{ 0 }; i < (1 << N); ++i) {
		if (popcount(i) != N / 2) { continue; }

		vector<int>().swap(teamStart);
		vector<int>().swap(teamLink);
		for (int j{ 0 }; j < N; ++j) {
			if (i & (1 << j)) { teamStart.push_back(j); }
			else { teamLink.push_back(j); }
		}

		ret = min(ret, CalcDeff());
	}

	cout << ret;

	return 0;
}