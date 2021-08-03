// https://www.acmicpc.net/problem/2752

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[3];
	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	sort(a, a + 3);
	for (int i = 0; i < 3; ++i)
		cout << a[i] << '\n';
}