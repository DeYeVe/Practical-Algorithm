// https://www.acmicpc.net/problem/6603

#include <bits/stdc++.h>
using namespace std;

int k;
int nums[14];
int arr[14];
bool is_used[51];

void func(int n)
{
	if (n == 6)
	{
		for (int i = 0; i < n; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < k; ++i)
	{
		if (n == 0 || arr[n - 1] < nums[i] && !is_used[nums[i]])
		{
			arr[n] = nums[i];
			is_used[nums[i]] = true;
			func(n + 1);
			is_used[nums[i]] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{ 
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; ++i)
		{
			cin >> nums[i];
		}
		func(0);
		cout << '\n';
	}
}