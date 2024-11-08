// https://www.acmicpc.net/problem/1920

#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int N;

int search(int target)
{
	int st = 0;
	int ed = N - 1;

	int mid = (ed + st) / 2;

	while (true)
	{
		if (arr[mid] == target)
			return 1;

		if (st >= ed)
			return 0;

		if (arr[mid] > target)
		{
			ed = mid - 1;
			mid = (ed + st) / 2;
		}
		else if (arr[mid] < target)
		{
			st = mid + 1;
			mid = (ed + st) / 2;
		}
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;

	while (M--)
	{
		int x;
		cin >> x;
		cout << search(x) << "\n";
	}
}