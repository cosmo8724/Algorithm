/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, elem, highest, ret;
vector<int> box(1001, 0);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> elem;
		cin >> box[elem];

		if (box[highest] < box[elem]) {
			highest = elem;
		}
	}

	int h = 0;
	for (int i = 1; i < highest; i++) {
		h = max(h, box[i]);
		ret += h;
	}

	h = 0;
	for (int i = 1000; i > highest; i--) {
		h = max(h, box[i]);
		ret += h;
	}

	cout << ret + box[highest];

	return 0;
}