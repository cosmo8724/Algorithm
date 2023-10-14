/* 23. 08. 23 */
#include <bits/stdc++.h>

using namespace std;

int n, ret, cur;
string s;
stack<int> st;

int main()
{
	cin >> n >> s;

	st.push(-1);

	for (int i{ 0 }; i < n; ++i) {
		if (s[i] == '(') { st.push(i); }
		else {
			st.pop();
			if (st.size()) { ret = max(ret, i - st.top()); }
			else { st.push(i); }
		}
	}

	cout << ret;

	return 0;
}