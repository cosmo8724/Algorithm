/* 23. 09. 12 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<double> v;
double ret, cur{ 1.f };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	cin >> v[0];
	cur = v[0];
	for (int i{ 1 }; i < N; ++i) {
		cin >> v[i];

		if (v[i] > cur * v[i]) { cur = v[i]; }
		else { cur *= v[i]; }

		ret = max(ret, cur);
	}

	cout << fixed << setprecision(3) << ret;

	return 0;
}