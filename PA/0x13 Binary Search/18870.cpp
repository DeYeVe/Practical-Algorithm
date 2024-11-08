// https://www.acmicpc.net/problem/18870

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> arr;
	vector<int> sorted;

	while (N--)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sorted = arr;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());


	for (int i = 0; i < arr.size(); i++)
	{
		cout << lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() << " ";
	}
}