// https://www.acmicpc.net/problem/1026

#include <bits/stdc++.h>
using namespace std;

int main(void)
{

	int N;
	int res = 0;

	cin >> N;

	priority_queue<int> A;
	priority_queue<int, vector<int>, greater<int>> B;

	for (int i = 0; i < N; ++i)
	{
		int in;
		cin >> in;
		A.push(in);
	}

	for (int i = 0; i < N; ++i)
	{
		int in;
		cin >> in;
		B.push(in);
	}

	for (int i = 0; i < N; ++i)
	{
		int a = A.top();
		int b = B.top();
		A.pop();
		B.pop();

		res += a * b;
	}

	cout << res;
}