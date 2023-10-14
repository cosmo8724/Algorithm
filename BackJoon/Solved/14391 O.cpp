/* 23. 08. 22 */
#include <bits/stdc++.h>

using namespace std;

int N, M, ret;
vector<vector<int>> mp;

int main()
{
	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(M, 0)).swap(mp);

	for (int i{ 0 }; i < N; ++i) {
		string s;
		cin >> s;
		for (int j{ 0 }; j < M; ++j) {
			mp[i][j] = s[j] - '0';
		}
	}

	for (int t{ 0 }; t < (1 << N * M); ++t) {
		int sum = 0;

		for (int i{ 0 }; i < N; ++i) {

			int token = 0;
			for (int j{ 0 }; j < M; ++j) {
				int k = i * M + j;

				if (t & (1 << k)) {
					sum += token;
					token = 0;
				}
				else {
					token = token * 10 + mp[i][j];
				}
			}
			sum += token;
		}

		for (int j{ 0 }; j < M; ++j) {

			int token = 0;
			for (int i{ 0 }; i < N; ++i) {
				int k = i * M + j;

				if (t & (1 << k)) {
					token = token * 10 + mp[i][j];
				}
				else {
					sum += token;
					token = 0;
				}
			}
			sum += token;
		}

		ret = max(sum, ret);
	}

	cout << ret;

	return 0;
}