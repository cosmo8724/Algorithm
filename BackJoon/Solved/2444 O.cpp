/* 23. 08. 28 */
#include <bits/stdc++.h>

using namespace std;

int N, idx;

int main()
{
	cin >> N;
	idx = N;

	for (int i{ 1 }; i < N * 2; i += 2) {
		idx--;

		for (int j{ idx }; j > 0; --j) { cout << ' '; }
		for (int j{ 0 }; j < i; ++j) { cout << '*'; }
		//for (int j{ idx }; j > 0; --j) { cout << ' '; }

		cout << '\n';
	}
	for (int i{ N * 2 - 3 }; i > 0; i -= 2) {
		idx++;

		for (int j{ idx }; j > 0; --j) { cout << ' '; }
		for (int j{ 0 }; j < i; ++j) { cout << '*'; }
		//for (int j{ idx }; j > 0; --j) { cout << ' '; }

		cout << '\n';
	}

	return 0;
}