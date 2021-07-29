// https://www.acmicpc.net/problem/2576

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[7];
	int min = 100, sum = 0;

	for (int i = 0; i < 7; ++i)
		cin >> a[i];
	for (int i = 0; i < 7; ++i)
		if (a[i] % 2 == 1)
		{
			sum += a[i];
			if (a[i] < min)
				min = a[i];
		}
	if (min == 100)
		cout << -1;
	else
		cout << sum << '\n' << min;
}