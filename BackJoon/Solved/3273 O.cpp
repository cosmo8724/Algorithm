/* 23. 08. 31 */
#include <bits/stdc++.h>

using namespace std;

int n, x, l, r, ret;
vector<int> v;

int main()
{
	cin >> n;
	v.resize(n);
	l = 0;
	r = n - 1;

	for (int i{ 0 }; i < n; ++i) { cin >> v[i]; }
	cin >> x;
	sort(begin(v), end(v));

	while (l != r) {
		if (v[l] + v[r] == x) {
			++ret;
			++l;
		}
		else if (v[l] + v[r] > x) { --r; }
		else { ++l; }
	}

	cout << ret;

	return 0;
}