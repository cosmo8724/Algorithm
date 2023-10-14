/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	vector<vector<int>>(N, vector<int>(N)).swap(v);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j <= i; ++j) {
			cin >> v[i][j];
		}
	}

	for (int i{ 1 }; i < N; ++i) {
		for (int j{ 0 }; j <= i; ++j) {
			if (j == 0) { v[i][j] += v[i - 1][j]; }
			else if (j == i) { v[i][j] += v[i - 1][j - 1]; }
			else { v[i][j] += max(v[i - 1][j], v[i - 1][j - 1]); }
		}
	}

	cout << *max_element(begin(v[N - 1]), end(v[N - 1]));

	return 0;
}