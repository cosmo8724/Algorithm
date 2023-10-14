/* 23. 05. 23 */
#include <iostream>

using namespace std;

/* (a + b) % c = (a % c + b % c) % c */
/* (a * b) % c = (a % c * b % c) % c */
long long Mul(long long A, long long B, long long C)
{
	if (B == 1)
		return A % C;

	long long ret = Mul(A, B / 2, C);
	ret = (ret * ret) % C;

	if (B & 1)
		ret = (ret * A) % C;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A, B, C;
	cin >> A >> B >> C;

	cout << Mul(A, B, C);

	return 0;
}