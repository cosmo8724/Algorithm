/* 23. 08. 30 */
#include <bits/stdc++.h>

using namespace std;

int n;
string name, state;
map<string, bool, greater<string>> logs;

int main()
{
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		cin >> name >> state;
		if (state == "enter") { logs[name] = true; }
		else { logs[name] = false; }
	}

	for (const auto& [myname, mystate] : logs) {
		if (mystate) { cout << myname << '\n'; }
	}

	return 0;
}