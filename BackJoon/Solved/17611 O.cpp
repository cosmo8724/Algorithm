/* 23. 10. 19 */
#include <bits/stdc++.h>

using namespace std;

int N, ret;
vector<pair<int, int>> vertices;
vector<int> CrossByX(1'000'001), CrossByY(1'000'001);

int main()
{
	cin >> N;
	vertices.resize(N + 1);
	for (int i{ 0 }; i < N; ++i) {
		cin >> vertices[i].first >> vertices[i].second;
		vertices[i].first += 500'000;
		vertices[i].second += 500'000;
	}
	vertices[N] = vertices[0];

	for (int i{ 0 }; i < N; ++i) {
		auto [fromX, fromY] { vertices[i] };
		auto [toX, toY] { vertices[i + 1] };
		if (fromX == toX && fromY == toY) { continue; }

		if (fromX > toX) { swap(fromX, toX); }
		for (int j{ fromX + 1 }; j <= toX; ++j) { ++CrossByX[j]; }
		
		if (fromY > toY) { swap(fromY, toY); }
		for (int j{ fromY + 1 }; j <= toY; ++j) { ++CrossByY[j]; }
	}

	for (auto [x, y] : vertices) {
		ret = max(ret, max(CrossByX[x], CrossByY[y]));
	}

	cout << ret;

	return 0;
}