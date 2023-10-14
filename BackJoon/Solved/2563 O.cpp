/* 23. 08. 29 */
#include <bits/stdc++.h>

using namespace std;

int N, L, B, cnt;
deque<deque<bool>> paper(100, deque<bool>(100));

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; ++i) {
		cin >> L >> B;

		for (int j{ L }; j < L + 10; ++j) {
			for (int k{ B }; k < B + 10; ++k) {
				if (!paper[j][k]) { ++cnt; }
				paper[j][k] = true;
			}
		}
	}

	cout << cnt;

	return 0;
}