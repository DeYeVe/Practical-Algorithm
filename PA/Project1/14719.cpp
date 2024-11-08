// https://www.acmicpc.net/problem/14719

#include <bits/stdc++.h>
using namespace std;

int arr[501];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	pair<int, int> max = { 0, 0 };

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < w; ++i)
	{
		cin >> arr[i];

		if (max.second < arr[i])
		{
			max = { i, arr[i] };
		}
	}

	int left_highest = 0, right_highest = 0, sum = 0;

	for (int i = 0; i < max.first; ++i)
	{
		left_highest = arr[i] > left_highest ? arr[i] : left_highest;
		sum += left_highest - arr[i];
	}

	for (int i = w; i > max.first; --i)
	{
		right_highest = arr[i] > right_highest ? arr[i] : right_highest;
		sum += right_highest - arr[i];
	}

	cout << sum;
}