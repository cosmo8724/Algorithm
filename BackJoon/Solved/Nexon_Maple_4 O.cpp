/*
Input
ù��° �ٿ� ��� �����ۿ�Ȧ�� ������ N ���� �Էµȴ�.
���� �ٺ��ʹ� �����ۿ�Ȧ�� � ������ �����ϰ� �ִ��� �Էµȴ�.
������ ������ ����ũ�� ID �� ǥ�õǰ�, ���κ��� �ΰ��� �� ID �� �Է¹ް� �Ǵµ�,
�̵� ������ �����ۿ�Ȧ�� ���� ����Ǿ� �ִٰ� �����ϸ� �ȴ�.
(ID �� �ּҰ��� 0�̰� �ִ밪�� 2147483647�̴�.)

Output
�ڱ⺰�� �����ؼ� �����ۿ�Ȧ������ ���డ���� ���� �� N �� ������ ������ ���� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

map <int, vector<int>> universe;
map <int, bool> visited;
int Cnt, N, A, B, answer = 0;

int Counting(int index)
{
	visited[index] = true;
	int sum = 1;

	for (int i : universe[index])
		if (!visited[i])
			sum += Counting(i);

	return sum;
}

int main()
{
	cin >> Cnt >> N;

	while (Cnt--)
	{
		cin >> A >> B;
		universe[A].push_back(B);
		universe[B].push_back(A);
		visited[A] = false;
		visited[B] = false;
	}

	for (auto pair : universe)
	{
		if (!visited[pair.first])
		{
			int sum = Counting(pair.first);
			if (sum <= N)
				answer += sum;
		}
	}

	cout << answer << '\n';

	return 0;
}