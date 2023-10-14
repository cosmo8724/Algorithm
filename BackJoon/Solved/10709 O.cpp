/* 23. 08. 09 */
#include <bits/stdc++.h>

using namespace std;

int H, W;

int main()
{
	cin >> H >> W;
	vector<vector<int>> JOI(H, vector<int>(W, 0));
	string s;
	int cnt = -1;
	bool isNext = false;

	for (int i = 0; i < H; i++) {
		cin >> s;

		for (int j = 0; j < W; j++) {
			if (s[j] == 'c') {
				cnt = 0;
				isNext = true;
				JOI[i][j] = cnt;
			}
			else {
				if (isNext) {
					JOI[i][j] = ++cnt;
				}
				else {
					JOI[i][j] = cnt;
				}
			}
		}
		cnt = -1;
		isNext = false;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << JOI[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}