/* 23. 08. 11 */
#include <bits/stdc++.h>

using namespace std;

using HP = tuple<int, int, int>;

int N, elem, ret;
int dir[6][3] = {
	{ 9, 3, 1 }, { 9, 1, 3 }, { 3, 9, 1 }, { 3, 1, 9 }, { 1, 9, 3 }, { 1, 3, 9 }
};
vector<int> scv(3, 0);
vector<vector<vector<int>>> hp(61, vector<vector<int>>(61, vector<int>(61, 0)));

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> scv[i];
	}

	if (N == 1) {
		ret = scv[0] % 9 ? scv[0] / 9 + 1 : scv[0] / 9;
		cout << ret;
	}
	else {
		queue<HP> q;
		q.push(make_tuple(scv[0], scv[1], scv[2]));
		hp[scv[0]][scv[1]][scv[2]] = 1;

		while (q.size()) {
			auto [x, y, z] = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = max(0, x - dir[i][0]);
				int ny = max(0, y - dir[i][1]);
				int nz = max(0, z - dir[i][2]);

				if (hp[nx][ny][nz]) {
					continue;
				}

				hp[nx][ny][nz] = hp[x][y][z] + 1;
				q.push(make_tuple(nx, ny, nz));
			}
		}

		cout << hp[0][0][0] - 1;
	}

	return 0;
}