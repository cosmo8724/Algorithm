/* 23. 08. 16 */
#include <bits/stdc++.h>

using namespace std;

int N, ret = numeric_limits<int>::max();
vector<int> mp;

void ReverseRow(int row)
{
	if (row == N) {
		int sum = 0;
		for (int j = 1 << (N - 1); j > 0; j >>= 1) {
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				if (mp[i] & j) { cnt++; }
			}
			sum += min(cnt, N - cnt);
		}
		ret = min(sum, ret);
		return;
	}

	ReverseRow(row + 1);
	mp[row] = ~mp[row];
	ReverseRow(row + 1);
}

int main()
{
	cin >> N;
	vector<int>(N, 0).swap(mp);

	for (int i = 0; i < N; i++) {
		int value = 1 << (N - 1);
		string s;
		cin >> s;
		for (int j = 0; j < N; j++, value >>= 1) {
			if (s[j] == 'T') { mp[i] |= value; }
		}
	}

	ReverseRow(0);

	cout << ret;

	return 0;
}