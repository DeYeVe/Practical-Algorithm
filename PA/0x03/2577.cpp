// https://www.acmicpc.net/problem/2577

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, mul;
	int cnt[10] = {};

	cin >> a >> b >> c;

	mul = a * b * c;
	while (mul > 0)
	{
		cnt[mul % 10]++;
		mul /= 10;
	}

	for (auto e : cnt)
		cout << e << '\n';
}