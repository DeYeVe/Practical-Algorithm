// https://www.acmicpc.net/problem/2493

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> stck;
	stck.push({ 100000001, 0 });

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		while (stck.top().first < input)
			stck.pop();
		cout << stck.top().second << " ";
		stck.push({ input , i + 1 });
	}
}