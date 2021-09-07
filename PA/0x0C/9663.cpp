// https://www.acmicpc.net/problem/9663

#include <bits/stdc++.h>
using namespace std;

int cnt, n;
int is_used1[30];
int is_used2[30];
int is_used3[30];

void func(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (is_used1[i] || is_used2[cur + i] || is_used3[n - i + cur - 1])
			continue;
		is_used1[i] = 1;
		is_used2[cur + i] = 1;
		is_used3[n - i + cur - 1] = 1;
		func(cur + 1);
		is_used1[i] = 0;
		is_used2[cur + i] = 0;
		is_used3[n - i + cur - 1] = 0;

	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0);
	cout << cnt;
}