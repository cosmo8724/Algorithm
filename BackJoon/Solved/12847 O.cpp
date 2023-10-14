/* 23. 08. 08 */
#include <bits/stdc++.h>

using namespace std;

int n, m;
long long day, answer;
vector<long long> psum;

int main()
{
	cin >> n >> m;
	psum.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> day;
		psum[i] = psum[i - 1] + day;
	}

	for (int i = m; i <= n; i++) {
		answer = max(answer, psum[i] - psum[i - m]);
	}

	cout << answer;

	return 0;
}