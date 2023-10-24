/* 23. 10. 24 */
/* 사탕상자 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_CANDY{ 1'000'000 };
int N, Command;
vector<int> Cnt, SegmentTree;

int Query(int Here, int Start, int End, int Count)
{
	if (Start == End) { return Start; }

	int Mid{ (Start + End) >> 1 };
	if (SegmentTree[Here << 1] >= Count) {
		return Query(Here << 1, Start, Mid, Count);
	}
	return Query((Here << 1) + 1, Mid + 1, End, Count - SegmentTree[Here << 1]);
}

void Update(int Here, int Start, int End, int Index, int Count)
{
	if (Index < Start || Index > End) { return; }

	SegmentTree[Here] += Count;

	if (Start != End) {
		int Mid{ (Start + End) >> 1 };
		Update(Here << 1, Start, Mid, Index, Count);
		Update((Here << 1) + 1, Mid + 1, End, Index, Count);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TreeHeight{ static_cast<int>(ceil(log2(MAX_CANDY))) };
	int TreeSize{ 1 << (TreeHeight + 1) };
	SegmentTree.resize(TreeSize);
	Cnt.resize(MAX_CANDY + 1);

	cin >> N;
	while (N--) {
		cin >> Command;
		if (Command == 1) {
			int Idx;
			cin >> Idx;
			int Pos{ Query(1, 1, MAX_CANDY, Idx) };
			cout << Pos << '\n';
			--Cnt[Pos];
			Update(1, 1, MAX_CANDY, Pos, -1);
		}
		else {
			int Value, Count;
			cin >> Value >> Count;
			Cnt[Value] += Count;
			Update(1, 1, MAX_CANDY, Value, Count);
		}
	}

	return 0;
}