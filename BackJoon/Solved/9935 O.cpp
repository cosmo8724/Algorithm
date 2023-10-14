/* 23. 09. 01 */
#include <bits/stdc++.h>

using namespace std;

string s, bomb, ret;

int main()
{
	cin >> s >> bomb;

	for (const char& sz : s) {
		ret.push_back(sz);

		int idx = ret.size() - bomb.size();
		if (idx >= 0) {
			if (ret.substr(idx, bomb.size()) == bomb) {
				ret.erase(idx, bomb.size());
			}
		}
	}

	if (ret == "") { cout << "FRULA"; }
	else { cout << ret; }

	return 0;
}