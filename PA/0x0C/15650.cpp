// https://www.acmicpc.net/problem/15650

#include <bits/stdc++.h>
using namespace std;

int nums[10];
bool is_used[10];
int n, m;

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; ++i)
			cout << nums[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (k == 0 || nums[k - 1] < i && !is_used[i])
		{
			nums[k] = i;
			is_used[i] = true;
			func(k + 1);
			is_used[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}