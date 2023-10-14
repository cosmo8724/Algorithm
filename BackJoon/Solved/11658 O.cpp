/* 23. 10. 09 */
#include <bits/stdc++.h>

using namespace std;

int N, M, oper, xA, xB, yA, yB;
vector<vector<int>> mp, tree;

int Sum(int y, int x)
{
	int ret{ 0 };
	while (y > 0) {
		int x_idx{ x };
		while (x_idx > 0) {
			ret += tree[y][x_idx];
			x_idx -= x_idx & -x_idx;
		}
		y -= y & -y;
	}
	return ret;
}

void Update(int y, int x, int value)
{
	while (y <= N) {
		int x_idx{ x };
		while (x_idx <= N) {
			tree[y][x_idx] += value;
			x_idx += x_idx & -x_idx;
		}
		y += y & -y;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<vector<int>>(N + 1, vector<int>(N + 1)).swap(mp);
	vector<vector<int>>(N + 1, vector<int>(N + 1)).swap(tree);

	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }; j <= N; ++j) {
			cin >> mp[i][j];
			Update(i, j, mp[i][j]);
		}
	}

	for (int i{ 0 }; i < M; ++i) {
		cin >> oper;
		if (oper == 0) {
			cin >> yA >> xA >> xB;
			Update(yA, xA, xB - mp[yA][xA]);
			mp[yA][xA] = xB;
		}
		else {
			cin >> yA >> xA >> yB >> xB;
			cout << Sum(yB, xB) - Sum(yA - 1, xB) - Sum(yB, xA - 1) + Sum(yA - 1, xA - 1) << '\n';
		}
	}

	return 0;
}