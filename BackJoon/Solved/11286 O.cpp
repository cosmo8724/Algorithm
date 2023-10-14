/* 23. 09. 02 */
#include <bits/stdc++.h>

using namespace std;

template <typename T> requires is_convertible<T, int>::value
class CompareAbs {
public:
	bool operator() (const T& a, const T& b) {
		T absA = abs(a), absB = abs(b);
		if (absA == absB) return a > b;
		else return absA > absB;
	}
};

int N, oper;
priority_queue<int, vector<int>, CompareAbs<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> N;
	while (N--) {
		cin >> oper;
		if (oper) {
			pq.push(oper);
		}
		else {
			if (pq.empty()) { cout << 0 << '\n'; }
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}