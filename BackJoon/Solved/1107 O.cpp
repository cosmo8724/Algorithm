/* 23.05.02 */
/* �� ���� �𸣰ڴ�. */
/* 23. 08. 11 ��Ʈ */
/* �� ������. ������. */
#include <bits/stdc++.h>

using namespace std;

int N, M, cnt, cur = 100;
vector<bool> broken(10, false);
vector<bool> channel(500000, true);

void Find(const string& num) {
	for (int i = 0; i < broken.size(); i++) {
		/* 4. ��ư�� ���峪�� �ʾ��� ��� */
		/* ù ��° �ڸ����� ���� �� �ִ� ��ư�� �� �������� */
		/* ��ư�� ���� �� +,- ��ư���� �����ϴ� Ƚ���� ���� */
		/* �� ��ư�� ������ �ϴ� Ƚ���� ����. */
		if (!broken[i]) {
			string nextnum = num + to_string(i);
			cnt = min(cnt, abs(stoi(nextnum) - N) + static_cast<int>(nextnum.size()));

			/* 5. 6�ڸ� ���ڰ� �� ������ ��� ȣ��. */
			if (nextnum.size() < 6) {
				Find(nextnum);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	while (M--) {
		int elem;
		cin >> elem;
		broken[elem] = true;
	}

	/* 1. �⺻������ +,- ��ư������ ������ �� �� �ִ� Ƚ���� ����. */
	cnt = abs(cur - N);

	/* 2. 0...9 ��ư�� ��� ���峵�ٸ� +,- ��ư������ �����ϹǷ� find �� �ʿ� ����. */
	if (M != 10) {
		/* 3. ���� �� �ִ� ��ư�� ������ ����� ������ ������ �ϴ� Ƚ���� ����. */
		Find("");
	}

	cout << cnt;

	return 0;
}