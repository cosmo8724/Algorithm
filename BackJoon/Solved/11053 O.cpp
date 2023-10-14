/* 23. 09. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, ret{ 0 };
vector<int> v, lis;

int main()
{
	cin >> N;
	v.resize(N);
	lis.resize(N);
	for (int i{ 0 }; i < N; ++i) {
		cin >> v[i];
		
		auto pos = lower_bound(begin(lis), begin(lis) + ret, v[i]);
		if (*pos == 0) { ++ret; }
		*pos = v[i];
	}

	cout << ret;

	return 0;
}