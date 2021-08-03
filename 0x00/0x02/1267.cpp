// https://www.acmicpc.net/problem/1267

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, y = 0 , m = 0;
	int a[20];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
	{
		y += (a[i] / 30 + 1) * 10;
		m += (a[i] / 60 + 1) * 15;
	}

	if (y == m)
		cout << "Y M " << y;
	else if (y < m)
		cout << 'Y' << ' ' << y;
	else
		cout << 'M' << ' ' << m;

}