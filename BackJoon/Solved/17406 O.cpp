/* 23. 09. 04 */
#include <bits/stdc++.h>

using namespace std;

int N, M, K, ret{ numeric_limits<int>::max() };
vector<vector<int>> v;
vector<tuple<int, int, int>> rotInfo;
vector<int> combi;
deque<bool> visited;

void Rotate(int stR, int stC, int edR, int edC, vector<vector<int>>& copyMap)
{
	int curVal = copyMap[stR][stC];

	for (int i = stC + 1; i <= edC; i++) { swap(curVal, copyMap[stR][i]); }
	for (int i = stR + 1; i <= edR; i++) { swap(curVal, copyMap[i][edC]); }
	for (int i = edC - 1; i >= stC; i--) { swap(curVal, copyMap[edR][i]); }
	for (int i = edR - 1; i >= stR; i--) { swap(curVal, copyMap[i][stC]); }
}

void dfs(int depth)
{
	if (depth == K) {
		vector<vector<int>> temp(v);
		for (int i : combi) {
			auto [r, c, s] { rotInfo[i] };
			int stR = r - s, stC = c - s;
			int edR = r + s, edC = c + s;
			for (int j{ 0 }; j < s; ++j) {
				Rotate(stR + j, stC + j, edR - j, edC - j, temp);
			}
		}
		for (int i{ 1 }; i <= N; ++i) {
			ret = min(ret, accumulate(begin(temp[i]) + 1, end(temp[i]), 0));
		}
		return;
	}

	for (int i{ 0 }; i < K; ++i) {
		if (visited[i]) { continue; }

		visited[i] = true;
		combi.push_back(i);
		dfs(depth + 1);
		visited[i] = false;
		combi.pop_back();
	}
}

int main()
{
	cin >> N >> M >> K;
	vector<vector<int>>(N + 1, vector<int>(M + 1)).swap(v);

	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }; j <= M; ++j) {
			cin >> v[i][j];
		}
	}

	for (int i{ 0 }; i < K; ++i) {
		int r, c, s;
		cin >> r >> c >> s;
		rotInfo.push_back(make_tuple(r, c, s));
	}

	visited.resize(K);
	dfs(0);

	cout << ret;

	return 0;
}