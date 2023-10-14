/* 23. 09. 05 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ 0, -1, 0, 1 };
int dx[]{ 1, 0, -1, 0 };
int N, x, y, d, g, ret;
vector<int> Lines[4][11];
bitset<101> visited[101];

void Draw_Line()
{
	for (int i{ 0 }; i < 4; ++i) {
		Lines[i][0].push_back(i);
		Lines[i][1].push_back((i + 1) % 4);

		for (int j{ 2 }; j < 11; ++j) {
			int size = Lines[i][j - 1].size();
			for (int k{ size - 1 }; k >= 0; --k) {
				Lines[i][j].push_back((Lines[i][j - 1][k] + 1) % 4);
			}
			for (int k{ 0 }; k < size; ++k) {
				Lines[i][j].push_back(Lines[i][j - 1][k]);
			}
		}
	}
}

void Go(int _x, int _y, int _d, int _g)
{
	visited[_x][_y] = true;
	for (int i{ 0 }; i <= g; ++i) {
		for (int _dir : Lines[d][i]) {
			_x += dx[_dir];
			_y += dy[_dir];
			visited[_x][_y] = true;
		}
	}
}

int main()
{
	cin >> N;
	Draw_Line();

	for (int i{ 0 }; i < N; ++i) {
		cin >> x >> y >> d >> g;
		Go(x, y, d, g);
	}

	for (int i{ 0 }; i <= 100; ++i) {
		for (int j{ 0 }; j <= 100; ++j) {
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) {
				++ret;
			}
		}
	}

	cout << ret;

	return 0;
}