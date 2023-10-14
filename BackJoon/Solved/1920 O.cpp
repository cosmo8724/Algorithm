/* 23.04.25 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	vector<int>	Ns;
	queue<int>	Ms;
	queue<int>	Checks;

	cin >> N;
	while (N--)
	{
		cin >> M;
		Ns.push_back(M);
	}

	cin >> M;
	while (M--)
	{
		cin >> N;
		Ms.push(N);
	}

	sort(Ns.begin(), Ns.end());

	while (Ms.size())
	{
		bool Check = false;

		Check = binary_search(Ns.begin(), Ns.end(), Ms.front());

		Checks.push(Check);
		Ms.pop();
	}

	while (Checks.size())
	{
		cout << Checks.front() << '\n';
		Checks.pop();
	}

	return 0;
}