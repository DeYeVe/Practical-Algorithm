// https://www.acmicpc.net/problem/11047

#include <bits/stdc++.h>
using namespace std;

int main(void)
{

	int N, K;
	int cnt = 0;

	cin >> N;
	cin >> K;

	priority_queue<int> pq;

	while (N--)
	{
		int i;
		cin >> i;
		pq.push(i);
	}

	while (K)
	{
		if (pq.top() <= K)
		{
			K -= pq.top();
			cnt++;
		}
		else
		{
			pq.pop();
		}
	}

	cout << cnt;
}