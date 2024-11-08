// https://www.acmicpc.net/problem/10773

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> stck;

	int k;
	cin >> k;

	while (k--)
	{
		int input;
		cin >> input;

		if (input)
			stck.push(input);
		else
			stck.pop();
	}

	int output = 0;
	while (!stck.empty())
	{
		output += stck.top();
		stck.pop();
	}

	cout << output;
}