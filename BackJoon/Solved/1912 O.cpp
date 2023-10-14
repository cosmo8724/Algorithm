/* 23. 09. 05 */
#include <bits/stdc++.h>

using namespace std;

int N, sum, ret = numeric_limits<int>::min();
vector<int> v;

int main()
{
	cin >> N;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }

	for (int i : v) {
		sum += i;
		ret = max(ret, sum);
		if (sum < 0) { sum = 0; }
	}

	return 0;
}