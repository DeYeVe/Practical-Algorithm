// https://www.acmicpc.net/problem/15665

#include <bits/stdc++.h>
using namespace std;

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
		before = nums[i];
		nums[k] = nums[i];
		func(k + 1);
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