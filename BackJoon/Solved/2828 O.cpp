/* 23. 08. 08 */
#include <bits/stdc++.h>

using namespace std;

int N, M, j, AppleLine, answer;
int L = 1, R;

int main()
{
	cin >> N >> M >> j;

	while (j--) {
		cin >> AppleLine;
		R = L + M - 1;

		if (L > AppleLine) {
			answer += L - AppleLine;
			L = AppleLine;
		}
		else if (R < AppleLine) {
			answer += AppleLine - R;
			L += AppleLine - R;
		}
	}

	cout << answer;

	return 0;
}