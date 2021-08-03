// https://www.acmicpc.net/problem/2490

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[3][4];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> a[i][j];

	int b[3] = { 0, };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
			b[i] += a[i][j];
		if (b[i] == 3)
			cout << 'A' << '\n';
		else if (b[i] == 2)
			cout << 'B' << '\n';
		else if (b[i] == 1)
			cout << 'C' << '\n';
		else if (b[i] == 0)
			cout << 'D' << '\n';
		else
			cout << 'E' << '\n';
	}
}