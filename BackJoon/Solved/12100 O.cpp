/* 23. 09. 04 */
#include <bits/stdc++.h>

using namespace std;

int N, ret;

class Board
{
public:
	Board(int N) : m_size(N) {
		vector<vector<int>>(N, vector<int>(N)).swap(m_vecBoard);
	}
	~Board() {}
	Board(const Board& rhs) = default;
	Board& operator= (const Board& rhs) = default;
	friend istream& operator>> (istream& InStream, Board& bd) {
		cin >> bd.m_vecBoard[bd.m_curRow][bd.m_curCul++];
		if (bd.m_curCul == bd.m_size) { ++bd.m_curRow; bd.m_curCul = 0; }

		return InStream;
	}
	void Rotate() {
		vector<vector<int>> v(m_size, vector<int>(m_size));
		for (int i{ 0 }; i < m_size; ++i) {
			for (int j{ 0 }; j < m_size; ++j) {
				v[i][j] = m_vecBoard[m_size - j - 1][i];
			}
		}
		m_vecBoard.swap(v);
	}
	void Move() {
		vector<vector<int>> v(m_size, vector<int>(m_size));
		for (int i{ 0 }; i < m_size; ++i) {
			int curIdx = -1;
			bool flag = false;
			for (int j{ 0 }; j < m_size; ++j) {
				if (m_vecBoard[i][j] == 0) { continue; }
				if (flag && m_vecBoard[i][j] == v[i][curIdx]) {
					v[i][curIdx] *= 2;
					flag = false;
				}
				else {
					v[i][++curIdx] = m_vecBoard[i][j];
					flag = true;
				}
				m_maxValue = max(m_maxValue, v[i][curIdx]);
			}
		}
		m_vecBoard.swap(v);
	}
	const int Get_MaxValue() const { return m_maxValue; }

private:
	vector<vector<int>> m_vecBoard;
	int m_size;
	int m_maxValue = 0;
	int m_curRow = 0;
	int m_curCul = 0;
};

void Execute(Board& bd, int Depth)
{
	if (Depth == 5) {
		ret = max(ret, bd.Get_MaxValue());
		return;
	}
	for (int i{ 0 }; i < 4; ++i) {
		Board temp{ bd };
		temp.Move();
		Execute(temp, Depth + 1);
		bd.Rotate();
	}

	return;
}

int main()
{
	cin >> N;
	Board bd(N);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			cin >> bd;
		}
	}

	Execute(bd, 0);

	cout << ret;

	return 0;
}