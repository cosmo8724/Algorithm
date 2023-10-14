/* 23. 08. 23 */
#include <bits/stdc++.h>

using namespace std;

string A, B, ret;
int len, elem;

int main()
{
	cin >> A >> B;

	while (A.size() || B.size() || elem) {
		if (A.size()) {
			elem += A.back() - '0';
			A.pop_back();
		}
		if (B.size()) {
			elem += B.back() - '0';
			B.pop_back();
		}

		ret += elem % 10 + '0';
		elem /= 10;
	}

	reverse(ret.begin(), ret.end());

	cout << ret;

	return 0;
}