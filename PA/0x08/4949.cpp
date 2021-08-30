// https://www.acmicpc.net/problem/4949

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string s;
		getline(cin, s);
		if (s == ".")
			break;

		stack<char> stck;
		bool is_valid = true;

		for (auto ele : s)
		{
			if (ele == '(')
				stck.push(ele);
			else if (ele == '[')
				stck.push(ele);
			else if (ele == ')')
			{
				if (stck.empty() || stck.top() != '(')
				{
					is_valid = false;
					break;
				}
				else
					stck.pop();
			}
			else if (ele == ']')
			{
				if (stck.empty() || stck.top() != '[')
				{
					is_valid = false;
					break;
				}
				else
					stck.pop();
			}
		}
		if (!stck.empty())
			is_valid = false;

		if (is_valid)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}