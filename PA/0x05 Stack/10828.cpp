// https://www.acmicpc.net/problem/10828

#include <bits/stdc++.h>
using namespace std;

int stck[10001];
int pos;

void push(int x)
{
	stck[pos++] = x;
}
int pop()
{
	return (pos > 0) ? stck[--pos] : -1;
}
int size()
{
	return pos;
}
int empty()
{
	return !pos;
}
int top()
{
	return (pos > 0) ? stck[pos - 1] : -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> output;

	for (int i = 0; i < n; ++i)
	{
		string input;
		cin >> input;

		if (!input.compare("push"))
		{
			int pushin;
			cin >> pushin;
			push(pushin);
		}
		else if (!input.compare("pop"))
		{
			output.push_back(pop());
		}
		else if (!input.compare("size"))
		{
			output.push_back(size());
		}
		else if (!input.compare("empty"))
		{
			output.push_back(empty());
		}
		else if (!input.compare("top"))
		{
			output.push_back(top());
		}
	}

	for (auto ele : output)
		cout << ele << "\n";
}