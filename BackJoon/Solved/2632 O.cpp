/* 23. 09. 06 */
#include <bits/stdc++.h>

using namespace std;

int total, n, m, ret;
vector<int> pizzaA, pizzaB;
vector<int> psumA, psumB;
map<int, int> sumCntA, sumCntB;

void Counting(const int size, const vector<int>& psum, map<int, int>& sumCnt)
{
	for (int interval{ 1 }; interval <= size; ++interval) {
		for (int st{ interval }; st <= size + interval - 1; ++st) {
			int sum = psum[st] - psum[st - interval];
			++sumCnt[sum];
			if (interval == size) { break; }
		}
	}
}

int main()
{
	cin >> total >> n >> m;
	pizzaA.resize(n + 1);
	pizzaB.resize(m + 1);
	psumA.resize(2 * n + 1);
	psumB.resize(2 * m + 1);
	for (int i{ 1 }; i <= n; ++i) {
		cin >> pizzaA[i];
		psumA[i] = psumA[i - 1] + pizzaA[i];
	}
	for (int i{ n + 1 }; i <= 2 * n; ++i) { psumA[i] = psumA[i - 1] + pizzaA[i - n]; }
	for (int i{ 1 }; i <= m; ++i) {
		cin >> pizzaB[i];
		psumB[i] = psumB[i - 1] + pizzaB[i];
	}
	for (int i{ m + 1 }; i <= 2 * m; ++i) { psumB[i] = psumB[i - 1] + pizzaB[i - m]; }

	Counting(n, psumA, sumCntA);
	Counting(m, psumB, sumCntB);

	ret = sumCntA[total] + sumCntB[total];

	for (int i{ 1 }; i < total; ++i) {
		ret += sumCntA[i] * sumCntB[total - i];
	}

	cout << ret;

	return 0;
}