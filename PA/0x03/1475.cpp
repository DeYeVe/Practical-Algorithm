// https://www.acmicpc.net/problem/1475

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int arr[10] = {};
	cin >> n;

	if (n == 0)
	{
		cout << 1;
		return 0;
	}

	while (n > 0)
	{
		arr[n % 10]++;
		n /= 10;
	}

	int sixnine = (arr[6] + arr[9] + 1) / 2;
	arr[6] = sixnine;
	arr[9] = sixnine;

	cout << *max_element(arr, arr + 10);
}