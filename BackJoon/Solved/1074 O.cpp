/* 23. 08. 16 */
#include <bits/stdc++.h>

using namespace std;

int N, r, c, ret;

void go(int y, int x, int size)
{
	if (size == 1) {
		if (r == y && c == x) {
			cout << ret;
			return;
		}
	}

	if (r >= y && r < y + size && c >= x && c < x + size) {
		go(y, x, size >> 1);
		go(y, x + (size >> 1), size >> 1);
		go(y + (size >> 1), x, size >> 1);
		go(y + (size >> 1), x + (size >> 1), size >> 1);
	}
	else {
		ret += size * size;
	}
}

int main()
{
	cin >> N >> r >> c;

	go(0, 0, 1 << N);

	return 0;
}