// https://www.acmicpc.net/problem/15656

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

	for (int i = 0; i < n; ++i)
	{
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