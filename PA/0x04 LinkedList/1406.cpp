// https://www.acmicpc.net/problem/1406

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> l;
	string input;
	cin >> input;
	for (auto ele : input)
		l.push_back(ele);
	auto cursor = l.end();

	int q;
	cin >> q;
	while (q--)
	{
		char in;
		cin >> in;

		if (in == 'L')
		{
			if (cursor != l.begin())
				cursor--;
		}
		else if (in == 'D')
		{
			if (cursor != l.end())
				cursor++;
		}
		else if (in == 'B')
		{
			if (cursor != l.begin())
			{
				cursor--;
				cursor = l.erase(cursor);
			}
		}
		else if (in == 'P')
		{
			char c;
			cin >> c;
			l.insert(cursor, c);
		}
	}

	for (auto ele : l)
		cout << ele;
}
