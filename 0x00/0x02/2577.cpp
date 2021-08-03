// https://www.acmicpc.net/problem/2577

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, mul, num;
	int nums[10] = { 0, };
	cin >> a >> b >> c;
	mul = a * b * c;

	while (mul > 0)
	{
		num = mul % 10;
		nums[num]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; ++i)
		cout << nums[i] << '\n';
}