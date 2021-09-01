// https://www.acmicpc.net/problem/2447

#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void func(int r, int c, int n)
{
	if (n == 0)
		v[r][c] = '*';
	else
	{
		int third = n / 3;
		func(r, c, third);
		func(r, c + third, third);
		func(r, c + 2 * third, third);
		func(r + third, c, third);
		func(r + third, c + 2 * third, third);
		func(r + 2 * third, c, third);
		func(r + 2 * third, c + third, third);
		func(r + 2 * third, c + 2 * third, third);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		v.push_back(string(n, ' '));

	func(0, 0, n);
	for (auto ele : v)
	{
		cout << ele << '\n';
	}
}