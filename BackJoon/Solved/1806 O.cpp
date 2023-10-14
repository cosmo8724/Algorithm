/* 23. 09. 15 */
#include <bits/stdc++.h>

using namespace std;

int N, S, ret{ numeric_limits<int>::max() };
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;
	v.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }

	int sum{ 0 };
	auto l{ begin(v) }, r{ begin(v) };
	while (l <= r) {
		if (sum >= S) {
			ret = min(ret, static_cast<int>(distance(l, r)));
			sum -= *(l++);
		}
		else {
			if (r == end(v)) { break; }
			sum += *(r++);
		}

	}

	if (ret == numeric_limits<int>::max()) { cout << 0; }
	else { cout << ret; }

	return 0;
}