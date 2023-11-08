/* 23. 11. 07 */
/* 디스크 트리 */
#include <bits/stdc++.h>

using namespace std;

class Trie
{
public:
	void Insert(vector<string>&& str, int depth) {
		if (depth == str.size()) { return; }

		string& Current{ str[depth] };
		if (Childs.find(Current) == end(Childs)) {
			Childs[Current] = move(make_unique<Trie>());
		}
		Childs[Current]->Depth = depth;
		Childs[Current]->Insert(move(str), depth + 1);
	}
	void Print() {
		for (auto& [str, child] : Childs) {
			for (int i{ 0 }; i < child->Depth; ++i) {
				cout << ' ';
			}
			cout << str << '\n';
			child->Print();
		}
	}

public:
	map<string, unique_ptr<Trie>> Childs;
	int Depth{ 0 };
};

int N;
string S;
unique_ptr<Trie> Root{ make_unique<Trie>() };

vector<string> Split(string& str, const string& delimeter)
{
	vector<string> ret;
	size_t len{ str.size() };
	size_t pos;

	while ((pos = str.find(delimeter)) != string::npos) {
		ret.push_back(str.substr(0, pos));
		str.erase(0, pos + delimeter.size());
	}
	ret.push_back(str.substr(0, pos));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i{ 0 }; i < N; ++i) {
		cin >> S;
		Root->Insert(Split(S, "\\"), 0);
	}

	Root->Print();

	return 0;
}