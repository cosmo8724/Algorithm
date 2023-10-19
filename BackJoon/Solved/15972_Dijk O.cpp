#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int N, M, H;
vector<vector<int>> Heights;
vector<vector<vector<int>>> Holes;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

enum EDirection { UP, RIGHT, DOWN, LEFT };

void FillWater()
{
	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }; j <= M; ++j) {
			Heights[i][j] = H;
		}
	}
}

void HoleInformationInput()
{
	for (int i{ 1 }; i <= N + 1; ++i) {
		for (int j{ 1 }, Height; j <= M; ++j) {
			cin >> Height;
			Holes[i][j][UP] = Height;
			Holes[i - 1][j][DOWN] = Height;
		}
	}
	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }, Height; j <= M + 1; ++j) {
			cin >> Height;
			Holes[i][j][LEFT] = Height;
			Holes[i][j - 1][RIGHT] = Height;
		}
	}
}

void Enqueue(int y, int x, int Height)
{
	if (Heights[y][x] > Height) {
		Heights[y][x] = Height;
		pq.push(make_tuple(Height, y, x));
	}
}

void InitializeOutsideRects()
{
	for (int i{ 1 }; i <= N; ++i) {
		if (Holes[i][1][LEFT] != -1) { Enqueue(i, 1, Holes[i][1][LEFT]); }
		if (Holes[i][M][RIGHT] != -1) { Enqueue(i, M, Holes[i][M][RIGHT]); }
	}
	for (int i{ 1 }; i <= M; ++i) {
		if (Holes[1][i][UP] != -1) { Enqueue(1, i, Holes[1][i][UP]); }
		if (Holes[N][i][DOWN] != -1) { Enqueue(N, i, Holes[N][i][DOWN]); }
	}
}

int Dijk()
{
	InitializeOutsideRects();

	while (!pq.empty()) {
		auto [Height, CurrentY, CurrentX] { pq.top() };
		pq.pop();

		if (Height > Heights[CurrentY][CurrentX]) { continue; }

		for (int Dir{ 0 }, NextY, NextX; Dir < 4; ++Dir) {
			if (Holes[CurrentY][CurrentX][Dir] == -1) { continue; }
			NextY = CurrentY + dy[Dir];
			NextX = CurrentX + dx[Dir];

			if (NextY <= 0 || NextX <= 0 || NextY > N || NextX > M) { continue; }

			int NextHeight{ max(Heights[CurrentY][CurrentX], min(Holes[CurrentY][CurrentX][Dir], Heights[NextY][NextX])) };
			if (Heights[NextY][NextX] > NextHeight) {
				Heights[NextY][NextX] = NextHeight;
				pq.push(make_tuple(NextHeight, NextY, NextX));
			}
		}
	}

	int Ret{ 0 };
	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }; j <= M; ++j) {
			Ret += Heights[i][j];
		}
	}

	return Ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> H;
	vector<vector<int>>(N + 1, vector<int>(M + 1, H)).swap(Heights);
	vector<vector<vector<int>>>(N + 2, vector<vector<int>>(M + 2, vector<int>(4, -1))).swap(Holes);

	//FillWater();
	HoleInformationInput();
	cout << Dijk();

	return 0;
}