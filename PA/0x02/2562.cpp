// https://www.acmicpc.net/problem/2562

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int a[9];
	int max = 0, max_idx = 0;

	for (int i = 0; i < 9; ++i)
		cin >> a[i];
	for (int i = 0; i < 9; ++i)
		if (a[i] > max)
		{
			max = a[i];
			max_idx = i + 1;
		}
	cout << max << '\n' << max_idx;
}