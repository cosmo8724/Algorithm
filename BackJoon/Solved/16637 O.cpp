/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int N, ret = numeric_limits<int>::min();
string s;
vector<int> num;
vector<char> vecOper;

int Oper(char _oper, int a, int b)
{
	if (_oper == '+') return a + b;
	else if (_oper == '-') return a - b;
	else if (_oper == '*') return a * b;
}

void psum(int idx, int _num)
{
	if (idx == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}

	psum(idx + 1, Oper(vecOper[idx], _num, num[idx + 1]));
	
	if (idx + 2 < num.size()) {
		int tmp = Oper(vecOper[idx + 1], num[idx + 1], num[idx + 2]);
		psum(idx + 2, Oper(vecOper[idx], _num, tmp));
	}
}

int main()
{
	cin >> N >> s;
	for (int i = 0; i < N; i++) {
		if (i & 1) {
			vecOper.push_back(s[i]);
		}
		else {
			num.push_back(s[i] - '0');
		}
	}

	psum(0, num[0]);

	cout << ret;

	return 0;
}