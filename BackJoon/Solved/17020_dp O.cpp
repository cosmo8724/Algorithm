/* 23. 10. 20 */
/* 핸드폰 번호 궁합 */
#include <bits/stdc++.h>

using namespace std;

string A, B;
queue<int> q;

int main()
{
	cin >> A >> B;
	for (int i{ 0 }; i < 8; ++i) {
		q.push(A[i] - '0');
		q.push(B[i] - '0');
	}

	int len{ 15 };
	while (q.size() != 2) {
		for (int i{ 0 }; i < len; ++i) {
			int num{ q.front() };
			q.pop();
			q.push((q.front() + num) % 10);
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