/* 23. 10. 05 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> v;

int main()
{
	cin >> N >> K;
	v.resize(N + 1);
	for (int i{ 2 }; i <= N; ++i) {
		if (v[i]) { continue; }
		for (int j{ i }; j <= N; j += i) {
			v[j] = max(v[j], i);
		}
	}

	cout << count_if(cbegin(v) + 1, cend(v), [](const int num) { return num <= K; });

	return 0;
}