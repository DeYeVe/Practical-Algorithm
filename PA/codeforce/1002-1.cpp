#include <bits/stdc++.h>

using namespace std;

int T;
string func()
{
	set<int> A;
	set<int> B;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int in;
		cin >> in;
		A.insert(in);
	}
	for (int i = 0; i < N; i++)
	{
		int in;
		cin >> in;
		B.insert(in);
	}

	if (A.size() >= 3 || B.size() >= 3)
	{
		return "YES";
	}

	if (A.size() == 2 && B.size() == 2)
	{
		return "YES";
	}

	return "NO";
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cout << func() << "\n";
	}
}