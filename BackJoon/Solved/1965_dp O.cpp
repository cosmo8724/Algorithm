/* 23. 11. 10 */
/* 상자넣기 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> boxes, dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	boxes.resize(N);
	vector<int>(N, 1).swap(dp);

	for (int i{ 0 }; i < N; ++i) { cin >> boxes[i]; }

	for (int i{ 1 }; i < N; ++i) {
		for (int j{ 0 }; j < i; ++j) {
			if (boxes[j] < boxes[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(begin(dp), end(dp));

	return 0;
}