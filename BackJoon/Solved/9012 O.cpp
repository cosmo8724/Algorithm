/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, strsize;
string s;
stack<char> st;

int main()
{
	cin >> N;

	while (N--) {
		cin >> s;

		if (s[0] == ')') {
			cout << "NO" << '\n';
			continue;
		}

		strsize = s.size();

		for (int i = 0; i < strsize; i++) {
			if (st.empty()) {
				st.push(s[i]);
			}
			else {
				if (s[i] == ')') {
					if (st.top() == '(') {
						st.pop();
					}
					else {
						st.push(s[i]);
					}
				}
				else {
					st.push(s[i]);
				}
			}
		}

		if (st.empty()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';

			while (st.size()) {
				st.pop();
			}
		}
	}

	return 0;
}