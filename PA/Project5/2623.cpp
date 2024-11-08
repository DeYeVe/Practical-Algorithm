// https://www.acmicpc.net/problem/2623

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int>> out(1001);
	int indegree[1001] = { 0, };
	vector<int> res;

	int N, M;
	cin >> N >> M;

	while (M--)
	{
		int L, a, b;
		cin >> L >> a;
		L--;

		while (L--)
		{
			cin >> b;
			out[a].push_back(b);
			indegree[b]++;

			a = b;
		}
	}

	queue<int> Q;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			Q.push(i);
			res.push_back(i);
		}
	}

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		for (auto nxt : out[cur])
		{
			if (--indegree[nxt] == 0)
			{
				Q.push(nxt);
				res.push_back(nxt);
			}
		}
	}

	if (res.size() != N)
		cout << 0;
	else
	{
		for (auto e : res)
			cout << e << "\n";
	}
}