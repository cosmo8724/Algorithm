/* 23. 09. 19 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

int dy[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
int N, M, K;
vector<vector<int>> mp, S2D2;
array<array<vector<int>, 11>, 11> trees;

void Spring()
{
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			sort(begin(trees[i][j]), end(trees[i][j]));

			for (int& y_o : trees[i][j]) {
				if (mp[i][j] >= y_o) {
					mp[i][j] -= y_o;
					++y_o;
				}
				else { y_o *= -1; }
			}
		}
	}
}

void Summer()
{
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			for (auto iter{ begin(trees[i][j]) }; iter != end(trees[i][j]); ) {
				if (*iter < 0) {
					mp[i][j] -= *iter / 2;
					iter = trees[i][j].erase(iter);
				}
				else { ++iter; }
			}
		}
	}
}

void Autumn()
{
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			for (int& y_o : trees[i][j]) {
				if (y_o % 5 == 0) {
					for (int dir{ 0 }; dir < 8; ++dir) {
						int ny{ i + dy[dir] };
						int nx{ j + dx[dir] };
						if (ny < 0 || nx < 0 || ny >= N || nx >= N) { continue; }
						trees[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			mp[i][j] += S2D2[i][j];
		}
	}
}

int Count()
{
	int ret{ 0 };
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			ret += trees[i][j].size();
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	vector<vector<int>>(N, vector<int>(N, 5)).swap(mp);
	vector<vector<int>>(N, vector<int>(N)).swap(S2D2);
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			cin >> S2D2[i][j];
		}
	}

	for (int i{ 0 }; i < M; ++i) {
		int y, x, year;
		cin >> y >> x >> year;
		trees[--y][--x].push_back(year);
	}

	for (int year{ 0 }; year < K; ++year) {
		Spring();
		Summer();
		Autumn();
		if (year == K) { break; }
		Winter();
	}

	cout << Count();
	
	return 0;
}