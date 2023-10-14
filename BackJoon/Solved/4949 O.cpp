/* 23.05.02 */
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
	stack<char> bracestack;
	vector<string> str;
	string Sentence;

	while (true) {
		getline(cin, Sentence);

		if (Sentence == ".")
			break;

		str.push_back(Sentence);
	}

	for (auto& tmp : str)
	{
// 		while (!bracestack.empty())
// 			bracestack.pop();

		for (char& word : tmp)
		{
			if (word == ' ')
				continue;

			if (word == '.')
			{
				if (bracestack.size() == 0)
					cout << "yes\n";
				else
					cout << "no\n";
			}

			if (word == '(' || word == '[')
				bracestack.push(word);

			if (word == ')')
			{
				if (bracestack.empty() == true)
				{
					cout << "no\n";
					break;
				}
				else
				{
					if (bracestack.top() == '(')
						bracestack.pop();
					else
					{
						cout << "no\n";
						break;
					}
				}
			}
			else if (word == ']')
			{
				if (bracestack.empty() == true)
				{
					cout << "no\n";
					break;
				}
				else
				{
					if (bracestack.top() == '[')
						bracestack.pop();
					else
					{
						cout << "no\n";
						break;
					}
				}
			}
		}

		stack<char>{}.swap(bracestack);
	}
}