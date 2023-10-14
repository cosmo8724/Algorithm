/* 23. 09. 12 */
#include <bits/stdc++.h>

using namespace std;

const int MAXNUM = numeric_limits<int>::max();
int N, len;
vector<int> v, inc_v;
vector<pair<int, int>> ret;
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);
	vector<int>(N, MAXNUM).swap(inc_v);
	ret.resize(N);
	for (int i{ 0 }; i < N; ++i) {
		cin >> v[i];

		auto pos = lower_bound(begin(inc_v), end(inc_v), v[i]);
		if (*pos == MAXNUM) { ++len; }
		*pos = v[i];

		ret[i].first = pos - begin(inc_v);
		ret[i].second = v[i];
	}
	
	cout << len << '\n';

	for (int i{ N - 1 }; i >= 0; --i) {
		if (ret[i].first == len - 1) {
			st.push(ret[i].second);
			--len;
		}
	}

	while (st.size()) {
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}