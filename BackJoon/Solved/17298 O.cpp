/* 23. 06. 15 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, tmp;
	stack<pair<int, int>> st;

	cin >> N;
	vector<int> nge(N, -1);

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;

		if (st.empty())
			st.push(pair<int, int>{tmp, i});
		else
		{
			if (st.top().first >= tmp)
				st.push(pair<int, int>{tmp, i});
			else
			{
				while (st.size() && st.top().first < tmp)
				{
					nge[st.top().second] = tmp;
					st.pop();
				}
				st.push(pair<int, int>{tmp, i});
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << nge[i] << ' ';

	return 0;
}