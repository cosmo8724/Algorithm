/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int k;
vector<bool> visited(10, false);
vector<char> oper;
vector<string> ret;

bool Check(char op, int a, int b) {
	if (op == '<') { return a < b; }
	else if (op == '>') { return a > b; }

	return false;
}

void dfs(int idx, string s)
{
	if (idx == k + 1) {
		ret.push_back(s);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i]) { continue; }

		if (idx == 0 || Check(oper[idx - 1], s[idx - 1], i + '0')) {
			visited[i] = true;
			dfs(idx + 1, s + to_string(i));
			visited[i] = false;
		}
	}

	return;
}

int main()
{
	cin >> k;
	vector<char>(k, 0).swap(oper);

	for (int i = 0; i < k; i++) {
		cin >> oper[i];
	}

	dfs(0, "");

	sort(ret.begin(), ret.end());

	cout << ret.back() << '\n' << ret.front();

	return 0;
}