// https://www.acmicpc.net/problem/6198

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> stck;
	stck.push(1000000001);

	long long output = 0;

	int n;
	cin >> n;
	while (n--)
	{
		int h;
		cin >> h;
		while (stck.top() <= h)
			stck.pop();
		output += stck.size() - 1;
		stck.push(h);
	}

	cout << output;
}