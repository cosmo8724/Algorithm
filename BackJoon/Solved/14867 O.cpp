/* 23. 09. 20 */
#include <bits/stdc++.h>

using namespace std;

int max_a, max_b, target_a, target_b, ret{ numeric_limits<int>::max() };

vector<function<void(int&, int&)>> oper{
	[](int& current_a, int&) { current_a = max_a; },
	[](int&, int& current_b) { current_b = max_b; },
	[](int& current_a, int&) { current_a = 0; },
	[](int&, int& current_b) { current_b = 0; },
	[](int& current_a, int& current_b) {
		if (current_a <= max_b - current_b) {
			current_b += current_a;
			current_a = 0;
		}
		else {
			current_a -= max_b - current_b;
			current_b = max_b;
		}
	},
	[](int& current_a, int& current_b) {
		if (current_b <= max_a - current_a) {
			current_a += current_b;
			current_b = 0;
		}
		else {
			current_b -= max_a - current_a;
			current_a = max_a;
		}
	}
};

int bfs(int current_a, int current_b)
{
	queue<pair<int, int>> q;
	q.push(make_pair(current_a, current_b));

	map<pair<int, int>, int> visited;
	visited[make_pair(current_a, current_b)] = 1;

	while (!q.empty()) {
		auto [a, b] { q.front() };
		q.pop();
		if (a == target_a && b == target_b) { break; }

		for (int i{ 0 }; i < 6; ++i) {
			int na{ a }, nb{ b };
			oper[i](na, nb);
			if (visited[make_pair(na, nb)]) { continue; }
			visited[make_pair(na, nb)] = visited[make_pair(a, b)] + 1;
			q.push(make_pair(na, nb));
		}
	}

	return visited[make_pair(target_a, target_b)] - 1;
}

int main()
{
	cin >> max_a >> max_b >> target_a >> target_b;

	cout << bfs(0, 0);

	return 0;
}