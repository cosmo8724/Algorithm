/* 23. 08. 31 */
#include <bits/stdc++.h>

using namespace std;

template <class T>
concept IsPair = requires(T t) {
	t.first;
	t.second;
};

template <typename T> requires IsPair<T>
	class Compare {
	public:
		bool operator() (const T& tA, const T& tB)
		{
			if (tA.second == tB.second) {
				return tA.first < tB.first;
			}

			return tA.second > tB.second;
		}
};

int N, d, p, ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare<pair<int, int>>> pq;

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; ++i) {
		cin >> p >> d;
		pq.push(make_pair(p, d));
	}

	//while (pq.size()) {
	//	cout << pq.top().first << ' ' << pq.top().second << '\n';
	//	pq.pop();
	//}
	
	priority_queue<int, vector<int>, greater<int>> ret_pq;
	while (pq.size()) {
		ret_pq.push(pq.top().first);
		if (ret_pq.size() > pq.top().second) { ret_pq.pop(); }
		pq.pop();
	}
	while (ret_pq.size()) {
		ret += ret_pq.top();
		ret_pq.pop();
	}

	cout << ret;

	return 0;
}