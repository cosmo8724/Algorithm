/* 23. 10. 18 */
#include <bits/stdc++.h>

using namespace std;

vector<int> Cells;
vector<int> RollIndex[6]{
	{ 0, 2, 8, 6, 1, 5, 7, 3, 51, 31, 41, 21, 50, 30, 40, 20, 52, 32, 42, 22 },
	{ 10, 12, 18, 16, 11, 15, 17, 13, 56, 26, 46, 36, 57, 27, 47, 37, 58, 28, 48, 38 },
	{ 20, 22, 28, 26, 21, 25, 27, 23, 0, 40, 18, 58, 3, 43, 15, 55, 6, 46, 12, 52 },
	{ 30, 32, 38, 36, 31, 35, 37, 33, 8, 50, 10, 48, 5, 53, 13, 45, 2, 56, 16, 42 },
	{ 40, 42, 48, 46, 41, 45, 47, 43, 6, 30, 16, 28, 7, 33, 17, 25, 8, 36, 18, 22 },
	{ 50, 52, 58, 56, 51, 55, 57, 53, 2, 20, 12, 38, 1, 23, 11, 35, 0, 26, 10, 32 }
};
vector<char> Color{ 'w', 'y', 'g', 'b', 'r', 'o' };
map<char, int> RotatePlane{
	{ 'U', 0 },
	{ 'D', 1 },
	{ 'L', 2 },
	{ 'R', 3 },
	{ 'F', 4 },
	{ 'B', 5 },
};

int TC, RollCount, Plane, D, E;
string RollInput;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> TC;
	while (TC--) {
		vector<int>(60).swap(Cells);
		for (int i{ 0 }; i < 60; ++i) {
			Cells[i] = i / 10;
		}

		cin >> RollCount;
		while (RollCount--) {
			cin >> RollInput;
			Plane = RotatePlane[RollInput[0]];
			if (RollInput[1] == '+') { D = 3; E = 1; }
			else { D = 1; E = 3; }

			for (int i{ 0 }, temp; i < 20; i += 4) {
				temp = Cells[RollIndex[Plane][i]];
				Cells[RollIndex[Plane][i]] = Cells[RollIndex[Plane][i + D]];
				Cells[RollIndex[Plane][i + D]] = Cells[RollIndex[Plane][i + 2]];
				Cells[RollIndex[Plane][i + 2]] = Cells[RollIndex[Plane][i + E]];
				Cells[RollIndex[Plane][i + E]] = temp;
			}
		}

		for (int i{ 0 }; i < 9; ) {
			cout << Color[Cells[i]];
			if (++i % 3 == 0) { cout << '\n'; }
		}
	}

	return 0;
}