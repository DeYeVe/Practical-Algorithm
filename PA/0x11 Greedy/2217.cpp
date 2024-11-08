//https://www.acmicpc.net/problem/2217

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N;
	cin >> N;

	int res = 0;


	priority_queue<int, vector<int>, greater<int>> MinHeap;

	for (int i = 0; i < N; i++)
	{
		int w;
		cin >> w;
		MinHeap.push(w);

	}

	for (int i = 0; i < N; i++)
	{
		res = max(res, MinHeap.top() * (N - i));
		MinHeap.pop();
	}

	cout << res;
}