/* 23. 08. 29 */
#include <bits/stdc++.h>

using namespace std;

int N, M, elem;
vector<vector<int>> v[2];

int main()
{
	cin >> N >> M;

	for (int i{ 0 }; i < 2; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			v[i].push_back(vector<int>{});
			for (int k{ 0 }; k < M; ++k) {
				cin >> elem;
				v[i][j].push_back(elem);
			}
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cout << v[0][i][j] + v[1][i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}