/* 23. 10. 26 */
/* 개미굴 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<string> Hierarchy;

void Print_Delimiter(int Count)
{
	while (Count--) {
		cout << "--";
	}
}

class Trie
{
public:
	void Insert(const vector<string>& _Hierarchy, const int Depth) {
		if (Depth == _Hierarchy.size()) { return; }

		if (!child[_Hierarchy[Depth]]) { child[_Hierarchy[Depth]] = std::move(make_unique<Trie>()); }
		child[_Hierarchy[Depth]]->Insert(_Hierarchy, Depth + 1);
	}

	void Print(const int Depth) {
		for (const auto& [Str, NextNode] : child) {
			Print_Delimiter(Depth);
			cout << Str << '\n';
			NextNode->Print(Depth + 1);
		}
	}

private:
	map<string, unique_ptr<Trie>> child;
};

int main()
{
	unique_ptr<Trie> Root{ make_unique<Trie>() };
	cin >> N;
	while (N--) {
		cin >> K;
		vector<string>(K).swap(Hierarchy);
		for (int i{ 0 }; i < K; ++i) { cin >> Hierarchy[i]; }

		Root->Insert(Hierarchy, 0);
	}

	Root->Print(0);

	return 0;
}