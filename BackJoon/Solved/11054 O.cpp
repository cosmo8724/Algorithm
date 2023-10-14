/* 23. 09. 27 */
#include <bits/stdc++.h>

using namespace std;

int N, ret;
vector<int> v, dp_less, dp_greater;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	vector<int>(N, 1).swap(dp_less);
	vector<int>(N, 1).swap(dp_greater);
	for (int i{ 0 }; i < N; ++i) {
		cin >> v[i];
		for (int j{ 0 }; j < i; ++j) {
			if (v[i] > v[j] && dp_less[i] < dp_less[j] + 1) {
				dp_less[i] = dp_less[j] + 1;
			}
		}
	}
	for (int i{ N - 1 }; i >= 0; --i) {
		for (int j{ N - 1 }; j > i; --j) {
			if (v[i] > v[j] && dp_greater[i] < dp_greater[j] + 1) {
				dp_greater[i] = dp_greater[j] + 1;
			}
		}
	}
	for (int i{ 0 }; i < N; ++i) {
		ret = max(ret, dp_less[i] + dp_greater[i] - 1);
	}

	cout << ret;
	
	return 0;
}