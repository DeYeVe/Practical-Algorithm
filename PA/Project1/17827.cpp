// https://www.acmicpc.net/problem/17827 

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V, loop;
	vector<int> v;

	cin >> N >> M >> V;
	loop = N - V + 1;

	while (N--)
	{
		int n;
		cin >> n;

		v.push_back(n);

	}

	while (M--)
	{
		int n;
		cin >> n;

		if (n < V)
		{
			cout << v[n] << "\n";
		}
		else
		{
			int t = (n - (V - 1)) % loop;
			cout << v[V + t - 1] << "\n";
		}
	}
}