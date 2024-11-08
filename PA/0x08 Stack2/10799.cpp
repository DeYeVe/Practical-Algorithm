// https://www.acmicpc.net/problem/10799

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int total = 0;
	string s;
	cin >> s;

	stack<char> stck;
	bool check_laser = false;

	for (auto ele : s)
	{
		if (ele == '(')
		{
			stck.push(ele);
			check_laser = true;
		}
		else // ')'
		{
			if (check_laser)
			{
				stck.pop();
				total += stck.size();
				check_laser = false;
			}
			else
			{
				stck.pop();
				total++;
			}
		}
	}
	cout << total;
}