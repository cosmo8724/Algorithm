/* 23. 09. 14 */
#include <bits/stdc++.h>

using namespace std;
using vvvi = vector<vector<vector<int>>>;
using vvi = vector<vector<int>>;


int T, W;
vvvi dp;
vector<int> fruit;

int Go(int fruit_idx, int tree, int cnt)
{
	if (fruit_idx == T) { return 0; }

	int& ret{ dp[fruit_idx][tree][cnt] };
	if (~ret) { return ret; }

	if (cnt > 0) { ret = Go(fruit_idx + 1, tree ^ 1, cnt - 1); }
	ret = max(ret, Go(fruit_idx + 1, tree, cnt)) + (tree == fruit[fruit_idx]);

	return ret;
}

int main()
{
	cin >> T >> W;
	vvvi(T, vvi(2, vector<int>(W + 1, -1))).swap(dp);
	fruit.resize(T);

	for (int i{ 0 }; i < T; ++i) {
		cin >> fruit[i];
		--fruit[i];
	}

	cout << max(Go(0, 0, W), Go(0, 1, W - 1));

	return 0;
}