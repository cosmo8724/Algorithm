/* 23. 05. 23 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct A {
	char a;
	double b;
	int c;
	short d;
	float e;
};

struct B
{
	A a;
	bool b;
};

class Base {
public:
	virtual void foo() { cout << "B_Foo" << endl; }
	void boo() { cout << "B_Boo" << endl; }
};

class Fxxk : public Base {
public:
	virtual void foo() override { cout << "D_Foo" << endl; }
	void boo() { cout << "D_Boo" << endl; }
};

void foo(int** p, int** q)
{
	int* t = *p;
	*p = *q;
	*q = t;
	**p = 3;
}

void Begin_Day(vector<int>& progresses, vector<int>& speeds)
{
	for (size_t i = 0; i < progresses.size(); i++)
		progresses[i] += speeds[i];
}

int Check_Progresses(queue<int*>& progress)
{
	int Cnt = 0;

	if (progress.size())
	{
		while (*(progress.front()) >= 100)
		{
			Cnt++;
			progress.pop();
		}
	}

	return Cnt;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int*> progress;

	for (size_t i = 0; i < progresses.size(); i++)
		progress.push(&progresses[i]);

	while (progress.size())
	{
		Begin_Day(progresses, speeds);

		int Cnt = Check_Progresses(progress);
		if (Cnt > 0)
			answer.push_back(Cnt);
	}

	return answer;
}

int main()
{
	vector<int> progresses{ 93, 30, 55 };
	vector<int> speeds{ 1, 30, 5 };
	vector<int> answer;

	answer = solution(progresses, speeds);

	/*int N;
	while (scanf_s("%d", &N) != EOF)
	{
		long long Num = 1, Cnt = 1;

		while (Num % N != 0)
		{
			Num = Num * 10 + 1;
			Num %= N;
			Cnt++;
		}

		cout << Cnt << '\n';
	}*/

	/*int i = 1, j = -1;
	int* Pi = &i;
	int* Pj = &j;
	foo(&Pi, &Pj);
	cout << *Pi << ' ' << *Pj;*/

	/*A a;
	B b;

	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;*/

	/*Fxxk fxxk;
	Base* cbase = static_cast<Base*>(&fxxk);

	fxxk.foo();
	cbase->foo();
	fxxk.boo();
	cbase->boo();*/

	/*������
	1. UTF-8�� �����ڵ带 ���� �˰�����̴�.
	2. UTF-8 UTF-16 ���� ������ ũ��?
	3. ASCII�� UTF-8�� �κ� �����̴�?
	4. ���� �˰�����̴�.

	Hash�Լ��� ���� �������� ���� ������ 2������
	1. �ϴ����Լ��̴�.
	2. ���� ���� ����.
	3. �Է°��� �����ϸ� ��°��� �����Ѱ� ����.
	4. 
	5. ���Լ��� �����Ѵ�.*/

	/*����
	1. sin()
	2. �����ϸ� 0�̴�.
	3. �����ϸ� �ﰢ�� ������ 2��
	4. �����ϸ� ����
	5. 

	C++
	1. ���� ���� ���� �ܺ� ���� ����

	A != B	C != D
	floating Point behavior		precise

	���� ��ť	3.5 / 25 / 7.5

	low high mid �ð����⵵
	O(logN)

	int sum(int n)
	{
		return n + sum(n - 1);
	}*/

	/*float e = 0.f;
	float a = 0.f / e;
	float b = 0.f / e;
	float c = 1.f / e;
	float d = 1.f / e;

	if (a == b)
		cout << "a == b" << endl;
	else
		cout << "a != b" << endl;

	if (c == d)
		cout << "c == d" << endl;
	else
		cout << "c != d" << endl;*/

	return 0;
}