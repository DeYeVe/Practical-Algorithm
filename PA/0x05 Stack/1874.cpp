// https://www.acmicpc.net/problem/1874

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> stck;
	string output;
	int n, idx = 1;
	cin >> n;

	
	while (n--)
	{
		int input;
		cin >> input;

		if (stck.empty())
		{
			stck.push(idx++);
			output += "+\n";
		}

		if (input < stck.top())
		{
			output = "NO";
			break;
		}

		if (input > stck.top())
		{
			int cnt = input - idx + 1;
			while (cnt--)
			{
				stck.push(idx++);
				output += "+\n";
			}
		}

		if (input == stck.top())
		{
			stck.pop();
			output += "-\n";
		};
	}

	cout << output;
}