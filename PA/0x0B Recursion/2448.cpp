// https://www.acmicpc.net/problem/2448

#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void func(int r, int c, int n)
{
	if (n == 3)
	{
		v[r][c] = '*';
		v[r + 1][c - 1] = '*';
		v[r + 1][c + 1] = '*';
		for (int i = 0; i < 5; ++i)
			v[r + 2][c - 2 + i] = '*';
	}
	else
	{
	int half = n / 2;
	func(r, c, n / 2);
	func(r + half, c - half, n / 2);
	func(r + half, c + half, n / 2);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		v.push_back(string(n * 2, ' '));

	func(0, n - 1, n);

	for (auto ele : v)
		cout << ele << '\n';
}