// https://www.acmicpc.net/problem/2309

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[9];
	int sum = 0;

	bool end_loop = false;	

	for (int i = 0; i < 9; ++i)
		cin >> a[i];

	for (int i = 0; i < 9; ++i)
		sum += a[i];

	for (int i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
			if (sum - a[i] - a[j] == 100)
			{
				a[i] = 0;
				a[j] = 0;
				end_loop = true;
				break;
			}
		if (end_loop)
			break;
	}
	sort(a, a + 9);

	for (int i = 2; i < 9; ++i)
		cout << a[i] << '\n';
}