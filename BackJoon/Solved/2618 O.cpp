/* 23. 09. 29 */
#include <bits/stdc++.h>

using namespace std;

int N, W;
vector<pair<int, int>> v;
vector<vector<int>> dp;

int GetDist(int idxFrom, int idxTo)
{
	return abs(v[idxFrom].first - v[idxTo].first) + abs(v[idxFrom].second - v[idxTo].second);
}

int Go(int policeA, int policeB)
{
	if (policeA == W + 1 || policeB == W + 1) { return 0; }

	int& ret{ dp[policeA][policeB] };
	if (ret) { return ret; }

	int next{ max(policeA, policeB) + 1 };
	return ret = min(Go(next, policeB) + GetDist(policeA, next), Go(policeA, next) + GetDist(policeB, next));
}

void PrintPath(int policeA, int policeB)
{
	for (int i{ 2 }; i < W + 2; ++i) {
		if (dp[i][policeB] + GetDist(policeA, i) < dp[policeA][i] + GetDist(policeB, i)) {
			cout << 1 << '\n';
			policeA = i;
		}
		else {
			cout << 2 << '\n';
			policeB = i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> W;
	v.resize(W + 2);
	vector<vector<int>>(W + 2, vector<int>(W + 2)).swap(dp);
	v[0] = make_pair(1, 1);
	v[1] = make_pair(N, N);
	for (int i{ 2 }; i < W + 2; ++i) { cin >> v[i].first >> v[i].second; }
	
	cout << Go(0, 1) << '\n';
	PrintPath(0, 1);
	
	return 0;
}