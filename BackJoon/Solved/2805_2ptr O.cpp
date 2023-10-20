/* 23. 10. 20 */
/* 나무 자르기 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
long long ret;
vector<int> trees;

long long Cut(long long height)
{
	long long ret{ 0 };
	const auto iter{ upper_bound(cbegin(trees), cend(trees), height) };
	for_each(iter, cend(trees), [&ret, &height](const int& tree) {
		ret += tree - height;
	});
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	trees.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> trees[i]; }
	sort(begin(trees), end(trees));

	long long l{ 0 };
	long long r{ trees.back() };
	while (l <= r) {
		long long mid{ (l + r) / 2 };

		if (Cut(mid) >= M) {
			l = mid + 1;
			ret = max(ret, mid);
		}
		else { r = mid - 1; }
	}

	cout << ret;

	return 0;
}