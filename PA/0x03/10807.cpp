// https://www.acmicpc.net/problem/10807

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, v, cnt = 0;
	int ints[100] = {};

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> ints[i];
	}
	cin >> v;

	for (int i = 0; i < n; ++i)
	{
		if (ints[i] == v)
			cnt++;
	}
	cout << cnt;
}