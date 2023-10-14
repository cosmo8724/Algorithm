/* 23. 09. 01 */
#include <bits/stdc++.h>

using namespace std;

long long N, ret;
vector<int> v, cnt(100'001);
vector<int>::const_iterator l, r;

int main()
{
	cin >> N;
	v.resize(static_cast<int>(N));

	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }

	l = cbegin(v);
	r = cbegin(v);

	while (l != cend(v)) {
		while (r != cend(v)) {
			if (!cnt[*r]) { ++cnt[*r]; }
			else { --cnt[*l]; break; }
			++r;
		}
		ret += r - l;
		++l;
	}

	cout << ret;

	return 0;
}