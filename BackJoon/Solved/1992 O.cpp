/* 23. 09. 05 */
#include <bits/stdc++.h>

using namespace std;

int N;
deque<deque<bool>> mp;

void QuadTree(int y, int x, int size)
{
	for (int i{ y }; i < y + size; ++i) {
		for (int j{ x }; j < x + size; ++j) {
			if (mp[i][j] != mp[y][x]) {
				cout << "(";
				QuadTree(y, x, size >> 1);
				QuadTree(y, x + (size >> 1), size >> 1);
				QuadTree(y + (size >> 1), x, size >> 1);
				QuadTree(y + (size >> 1), x + (size >> 1), size >> 1);
				cout << ")";
				return;
			}
		}
	}

	cout << mp[y][x];
}

int main()
{
	cin >> N;
	deque<deque<bool>>(N, deque<bool>(N)).swap(mp);

	for (int i{ 0 }; i < N; ++i) {
		string s;
		cin >> s;
		for (int j{ 0 }; j < s.size(); ++j) {
			mp[i][j] = s[j] - '0';
		}
	}

	QuadTree(0, 0, N);

	return 0;
}