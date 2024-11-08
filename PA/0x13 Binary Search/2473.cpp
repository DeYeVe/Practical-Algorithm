// https://www.acmicpc.net/problem/2473

#include <bits/stdc++.h>
using namespace std;
int N;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<long long> arr;
	long long res[3] = { 1000000001, 1000000001, 1000000001 };

	cin >> N;
	for (int i = 0; i < N; i++)
		{
			long long x;
			cin >> x;
			arr.push_back(x);
		}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			int idx = lower_bound(arr.begin(), arr.end(), -(arr[i] + arr[j])) - arr.begin();
			for (int k = -2; k <= 2; k++) {
				if (idx + k == i || idx + k == j)
					continue;
				if (idx + k < 0 || idx + k >= N)
					continue;
				if (abs(res[0] + res[1] + res[2]) > abs(arr[i] + arr[j] + arr[idx + k]))
				{
					res[0] = arr[i];
					res[1] = arr[j];
					res[2] = arr[idx + k];
				}
			}
		}

	sort(res, res + 2);

	for (auto e : res)
	{
		cout << e << " ";
	}
}