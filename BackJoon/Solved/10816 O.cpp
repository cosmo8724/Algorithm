/* 23. 08. 30 */
#include <bits/stdc++.h>

using namespace std;

int N, M, num;
map<int, int> mycard;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--) {
		cin >> num;
		++mycard[num];
	}

	cin >> M;

	for (int i{ 0 }; i < M; ++i) {
		cin >> num;
		if (mycard.find(num) == end(mycard)) { cout << 0 << ' '; }
		else { cout << mycard[num] << ' '; }
	}

	return 0;
}