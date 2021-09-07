// https://www.acmicpc.net/problem/15654

#include <bits/stdc++.h>
using namespace std;

bool is_used[10];
int nums[10];
vector<int> nums;
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

	for (int i = 0; i < n; ++i)
	{
		if (!is_used[i])
		{
			nums[k] = nums[i];
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
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		nums.push_back(input);
	}
	sort(nums.begin(), nums.end());
	func(0);
}