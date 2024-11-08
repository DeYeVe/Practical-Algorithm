// https://www.acmicpc.net/problem/2252

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	vector<vector<int>> out(32001);
	int indegree[32001] = { 0, };

	cin >> N >> M;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		out[a].push_back(b);
		indegree[b]++;
	}

	queue<int> Q;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		cout << cur << " ";

		for (auto ele : out[cur])
		{
			if (--indegree[ele] == 0)
				Q.push(ele);
		}
	}
}