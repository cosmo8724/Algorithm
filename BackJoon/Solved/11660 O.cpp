/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int N, M, stX, stY, edX, edY;
vector<vector<int>> v, psum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<vector<int>>(N + 1, vector<int>(N + 1)).swap(v);
	vector<vector<int>>(N + 1, vector<int>(N + 1)).swap(psum);

	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }; j <= N; ++j) {
			cin >> v[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + v[i][j];
		}
	}

	while (M--) {
		cin >> stX >> stY >> edX >> edY;
		cout << psum[edX][edY] - psum[stX - 1][edY] - psum[edX][stY - 1] + psum[stX - 1][stY - 1] << '\n';
	}

	return 0;
}