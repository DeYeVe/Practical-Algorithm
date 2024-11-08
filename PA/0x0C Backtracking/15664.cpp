// https://www.acmicpc.net/problem/15664

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

	int before = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i > 0 && nums[i] == before)
			continue;
		if (k != 0 && nums[k - 1] > nums[i])
			continue;
		if (!is_used[i])
		{
			before = nums[i];
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