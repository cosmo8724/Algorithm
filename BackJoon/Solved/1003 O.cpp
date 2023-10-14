/* 23. 08. 16 */
#include <bits/stdc++.h>

using namespace std;

int T, N, cnt[2][41];

int main()
{
	cin >> T;

	cnt[0][0] = 1; cnt[0][1] = 0;
	cnt[1][0] = 0; cnt[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		cnt[0][i] = cnt[0][i - 1] + cnt[0][i - 2];
		cnt[1][i] = cnt[1][i - 1] + cnt[1][i - 2];
	}

	while (T--) {
		cin >> N;
		cout << cnt[0][N] << ' ' << cnt[1][N] << '\n';
	}
}