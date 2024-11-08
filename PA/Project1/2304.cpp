// https://www.acmicpc.net/problem/2304

#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;
	pair<int, int> max = { 0, 0 };

	while (n--)
	{
		int l, h;
		cin >> l >> h;

		arr[l] = h;

		if (max.second < h)
		{
			max = { l, h };
		}
	}

	int left_highest = 0, right_highest = 0, sum = 0;

	for (int i = 0; i < max.first; ++i)
	{
		left_highest = arr[i] > left_highest ? arr[i] : left_highest;
		sum += left_highest;
	}

	for (int i = 1001; i > max.first; --i)
	{
		right_highest = arr[i] > right_highest ? arr[i] : right_highest;
		sum += right_highest;
	}

	sum += max.second;

	cout << sum;	
}