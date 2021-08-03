// https://www.acmicpc.net/problem/2587

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[5];
	int avg = 0, mid = 0;

	for (int i = 0; i < 5; ++i)
		cin >> a[i];

	for (int i = 0; i < 5; ++i)
		avg += a[i];
	avg /= 5;
	sort(a, a + 5);
	mid = a[2];
	
	cout << avg << '\n' << mid;
}