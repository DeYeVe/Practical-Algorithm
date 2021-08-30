// https://www.acmicpc.net/problem/9012

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		stack<char> stck;
		string s;
		cin >> s;
		bool is_valid = true;

		for (auto ele : s)
		{
			if (ele == '(')
				stck.push(ele);
			else // ')'
			{
				if (stck.empty())
				{
					is_valid = false;
					break;
				}
				stck.pop();
			}
		}
		
		if (!stck.empty())
			is_valid = false;

		if (is_valid)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}