/* 23. 08. 31 */
#include <bits/stdc++.h>

using namespace std;

int N;
double elem;
priority_queue<double, vector<double>, greater<double>> pq;

int main()
{
	cin >> N;
	while (N--) {
		cin >> elem;
		pq.push(elem);
	}

	cout << fixed << setprecision(3);

	for (int i{ 0 }; i < 7; ++i) {
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}