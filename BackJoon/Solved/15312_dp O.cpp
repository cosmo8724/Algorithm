/* 23. 10. 24 */
/* 이름 궁합 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

array<int, 26> cnt{ 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
string A, B;
size_t len;
queue<int> q;

int main()
{
	cin >> A >> B;
	len = A.size();

	for (size_t i{ 0 }; i < len; ++i) {
		q.push(cnt[A[i] - 'A']);
		q.push(cnt[B[i] - 'A']);
	}

	len *= 2;
	while (q.size() != 2) {
		for (size_t i{ 0 }; i < len - 1; ++i) {
			int current{ q.front() };
			q.pop();
			q.push((current + q.front()) % 10);
		}
		q.pop();
		--len;
	}

	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}

	return 0;
}