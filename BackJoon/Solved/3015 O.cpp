/* 23. 08. 24 */
#include <bits/stdc++.h>

using namespace std;

int N, elem;
long long ret;
stack<pair<long long, long long>> st;

int main()
{
	cin >> N;

	while (N--) {
		cin >> elem;
		int cnt = 1;
		
		while (st.size() && st.top().first <= elem) {
			ret += st.top().second;

			if (st.top().first == elem) { cnt = st.top().second + 1; }
			else { cnt = 1; }

			st.pop();
		}

		if (st.size()) { ++ret; }

		st.push({ elem, cnt });
	}

	cout << ret;

	return 0;
}