/* 23. 10. 27 */
/* 알고리즘 수업 - 피보나치 수 2 */
#include <bits/stdc++.h>

using namespace std;

const int MOD{ 1'000'000'007 };
int N;

int main()
{
	cin >> N;
	int a{ 1 }, b{ 1 }, c;

	for (int i{ 3 }; i <= N; ++i) {
		c = a % MOD + b % MOD;
		c %= MOD;
		swap(a, b);
		swap(b, c);
	}

	cout << b << ' ' << N - 2;

	return 0;
}