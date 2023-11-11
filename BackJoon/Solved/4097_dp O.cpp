/* 23. 11. 11 */
/* 수익 */
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> N;
		if (!N) { break; }

		int sum{ 0 }, answer{ numeric_limits<int>::min() };
		for (int i{ 0 }, value; i < N; ++i) {
			cin >> value;
			sum = sum + value > value ? sum + value : value;
			answer = max(answer, sum);
		}

		cout << answer << '\n';
	}

	return 0;
}