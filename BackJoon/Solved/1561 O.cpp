/* 23. 09. 11 */
#include <bits/stdc++.h>

using namespace std;

long long N, lo, hi{ 60'000'000'004 }, mid, _time;
int M;
vector<int> times;

bool Check(long long value) {
	long long cnt{ M };

	for (int i{ 0 }; i < M; ++i) { cnt += value / times[i]; }

	return cnt >= N;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	if (N <= M) {
		cout << N;
		return 0;
	}

	times.resize(M);
	for (int i{ 0 }; i < M; ++i) { cin >> times[i]; }

	while (lo <= hi) {
		mid = (lo + hi) / 2;

		if (Check(mid)) {
			hi = mid - 1;
			_time = mid;
		}
		else { lo = mid + 1; }
	}

	long long cnt{ M };
	for (int i{ 0 }; i < M; ++i) { cnt += (_time - 1) / times[i]; }
	for (int i{ 0 }; i < M; ++i) {
		if (_time % times[i] == 0) { ++cnt; }
		if (cnt == N) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}