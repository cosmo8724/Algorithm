/* 23. 08. 09 */
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
	cin >> N;

	int i = 666;
	for (i; N; i++) {
		if (to_string(i).find("666") != string::npos) {
			N--;
		}
	}

	cout << --i;

	return 0;
}