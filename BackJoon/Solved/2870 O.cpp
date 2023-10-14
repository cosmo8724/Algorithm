/* 23. 08. 08 */
#include <bits/stdc++.h>

using namespace std;

int N;
string str, word;
vector<string> v;

int main()
{
	cin >> N;
	while (N--) {
		cin >> word;

		for (auto sz : word) {
			if (isdigit(sz))
				str.push_back(sz);
			else {
				if (str != "") {
					while (str.size() > 1 && str[0] == '0') {
						str.erase(0, 1);
					}
					v.push_back(str);
					str = "";
				}
			}
		}

		if (str != "") {
			while (str.size() > 1 && str[0] == '0') {
				str.erase(0, 1);
			}
			v.push_back(str);
			str = "";
		}
	}

	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		if (a.size() == b.size())
			return a < b;
		return a.size() < b.size();
		});

	for (const string& s : v)
		cout << s << '\n';

	return 0;
}