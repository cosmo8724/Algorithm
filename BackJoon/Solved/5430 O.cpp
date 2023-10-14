/* 23. 08. 16 */
#include <bits/stdc++.h>

using namespace std;

int T, n;
string oper, s;

deque<int> Split(string_view sv, string_view delimeter)
{
	deque<int> ret;
	int pos = 0;
	int token = 0;

	if (sv.front() == '[') { sv.remove_prefix(1); }

	while ((pos = sv.find(delimeter)) != string_view::npos) {
		ret.push_back(stoi(sv.data()));
		sv.remove_prefix(pos + delimeter.size());
	}

	ret.push_back(stoi(sv.data()));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> oper >> n >> s;

		deque<int> dq;
		bool flag = false, reversed = false;

		if (n) {
			string num = "";
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '[' || s[i] == ']' || s[i] == ',') {
					if (num != "") { dq.push_back(stoi(num)); }
					num = "";
					continue;
				}
				num += s[i];
			}
		}

		for (int i = 0; i < oper.size(); i++) {
			if (oper[i] == 'R') { reversed = !reversed; }
			else {
				if (dq.empty()) {
					flag = true;
					break;
				}

				if (reversed) { dq.pop_back(); }
				else { dq.pop_front(); }
			}
		}

		if (flag) {
			cout << "error\n";
			continue;
		}

		s = "[";
		if (!reversed) {
			for (int i = 0; i < dq.size(); i++) {
				s += to_string(dq[i]) + ",";
			}
		}
		else {
			for (int i = dq.size() - 1; i >= 0; i--) {
				s += to_string(dq[i]) + ",";
			}
		}
		if (dq.size()) { s.pop_back(); }
		s += "]";

		cout << s << '\n';
	}

	return 0;
}