/* 23. 08. 28 */
#include <bits/stdc++.h>

using namespace std;

string s;
vector<string> alpha{ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main()
{
	cin >> s;

	for (const string& str : alpha) {
		int idx = 0;

		while (true) {
			if ((idx = s.find(str)) == string::npos) { break; }
			s.replace(idx, str.size(), "#");
		}
	}

	cout << s.size();

	return 0;
}