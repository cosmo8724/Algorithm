/* 23. 10. 24 */
/* 최대 상승 */
#include <bits/stdc++.h>

using namespace std;

int N, max_num{ numeric_limits<int>::min() }, ret;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }

	for (int i{ N - 1 }; i >= 0; --i) {
		max_num = max(max_num, v[i]);
		ret = max(ret, max_num - v[i]);
	}

	cout << ret;

	return 0;
}