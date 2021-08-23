// https://www.acmicpc.net/problem/1406

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	string output;
	
	for (int i = 0; i < q; ++i)
	{
		string input;
		cin >> input;

		list<char> l;
		auto cursor = l.end();
		for (auto ele : input)
		{
			if (ele == '-')
			{
				if (cursor != l.begin())
				{
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else if (ele == '<')
			{
				if (cursor != l.begin())
					cursor--;
			}
			else if (ele == '>')
			{
				if (cursor != l.end())
					cursor++;
			}
			else
				l.insert(cursor, ele);
		}
		for (auto ele : l)
			output += ele;
		output += '\n';
	}
	cout << output;
}