/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, M, ret = numeric_limits<int>::max();
vector<vector<int>> mp;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int ChickenDist(int y, int x, vector<int>& v)
{
	int dist = numeric_limits<int>::max();

	for (int i = 0; i < v.size(); i++) {
		dist = min(dist, abs(y - chicken[v[i]].first) + abs(x - chicken[v[i]].second));
	}

	return dist;
}

void Combination(int st, vector<int>& v)
{
	if (v.size() == M) {
		int total = 0;

		for (int i = 0; i < home.size(); i++) {
			total += ChickenDist(home[i].first, home[i].second, v);
		}

		ret = min(ret, total);
	}

	for (int i = st + 1; i < chicken.size(); i++) {
		v.push_back(i);
		Combination(i, v);
		v.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(N, 0)).swap(mp);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];

			if (mp[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (mp[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	vector<int> b;
	Combination(-1, b);
	
	cout << ret << '\n';

	return 0;
}