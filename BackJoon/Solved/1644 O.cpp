/* 23. 09. 01 */
#include <bits/stdc++.h>

using namespace std;

int N, sum, ret;
vector<int> primes;

vector<int> getPrimes(int num)
{
	deque<bool> nums(num + 1);
	vector<int> _ret;

	for (int i{ 2 }; i <= num; ++i) {
		if (nums[i]) { continue; }

		_ret.push_back(i);
		for (int j{ i * 2 }; j <= num; j += i) { nums[j] = true; }
	}

	return _ret;
}

int main()
{
	cin >> N;
	primes = getPrimes(N);

	vector<int>::const_iterator lo{ cbegin(primes) };
	vector<int>::const_iterator hi{ lo };
	while (lo != cend(primes)) {
		if (sum >= N) { sum -= *(lo++); }
		else { sum += *(hi++); }

		if (sum == N) { ++ret; }
	}

	cout << ret;

	return 0;
}