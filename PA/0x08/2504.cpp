// https://www.acmicpc.net/problem/2504

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int result = 0, buf = 1;
	stack<char> stck;
	bool add_value;

	for (auto ele : s)
	{
		if (ele == '(')
		{
			stck.push(ele);
			buf *= 2;
			add_value = true;
		}
		else if (ele == '[')
		{
			stck.push(ele);
			buf *= 3;
			add_value = true;
		}
		else if (ele == ')')
		{
			if (stck.empty() || stck.top() == '[')
			{
				result = 0;
				break;
			}
			if (stck.top() == '(' && add_value)
			{
				result += buf;
				add_value = false;
			}
			buf /= 2;
			stck.pop();
		}
		else if (ele == ']')
		{
			if (stck.empty() || stck.top() == '(')
			{
				result = 0;
				break;
			}
			if (stck.top() == '[' && add_value)
			{
				result += buf;
				add_value = false;
			}
			buf /= 3;
			stck.pop();
		}
	}
	if (!stck.empty())
		result = 0;
	cout << result;
}