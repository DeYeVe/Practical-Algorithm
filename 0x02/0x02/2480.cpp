// https://www.acmicpc.net/problem/2480

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, reward = 0;
	cin >> a >> b >> c;

	if (a == b && b == c)
		reward = 10000 + a * 1000;
	else if (a != b && b != c && a != c)
		reward = max({ a, b, c }) * 100;
	else if (a == b || b == c)
		reward = 1000 + b * 100;
	else
		reward = 1000 + a * 100;

	cout << reward;
}