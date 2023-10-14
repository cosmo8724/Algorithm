/* 23. 09. 08 */
#include <bits/stdc++.h>

using namespace std;

int N, idx, ret = 1;
vector<int> v, cnt, prev_list, max_vec;

int main()
{
	cin >> N;
	v.resize(N);
	vector<int>(N, 1).swap(cnt);
	vector<int>(N, -1).swap(prev_list);
	for (int i{ 0 }; i < N; ++i) { cin >> v[i]; }

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < i; ++j) {
			if (v[i] > v[j] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1;
				prev_list[i] = j;
				if (ret < cnt[i]) {
					ret = cnt[i];
					idx = i;
				}
			}
		}
	}

	cout << ret << '\n';
	int i{ idx };
	for (; prev_list[i] != -1; i = prev_list[i]) { max_vec.push_back(v[i]); }
	max_vec.push_back(v[i]);
	for (int i{ ret - 1 }; i >= 0; --i) { cout << max_vec[i] << ' '; }

	return 0;
}