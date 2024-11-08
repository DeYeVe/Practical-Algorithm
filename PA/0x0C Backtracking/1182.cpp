// https://www.acmicpc.net/problem/1182

#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int nums[22];

void func(int cur, int sum)
{
	if (cur == n)
	{
		if (sum == s)
			cnt++;
		return;
	}
	
	func(cur + 1, sum);
	func(cur + 1, sum + nums[cur]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	func(0, 0);
	if (s == 0)
		cnt--;
	cout << cnt;
}