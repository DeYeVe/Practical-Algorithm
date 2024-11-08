// https://www.acmicpc.net/problem/13335

#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> on_bridge;
	int truck[1002];
	int dist[1002];
	int cur_weight = 0;
	int n, w, l;
	int time = 1;
	int idx = 1;

	cin >> n >> w >> l;
	w++;
	for (int i = 1; i <= n; ++i)
		cin >> truck[i];

	for (int i = 1; i <= n; ++i)
		dist[i] = w;

	on_bridge.push_back(1);
	cur_weight += truck[1];
	dist[1] -= 1;

	while (!on_bridge.empty())
	{
		time++;
		int frt = on_bridge[0];
		if (dist[frt] == 1)
		{
			cur_weight -= truck[frt];
			on_bridge.erase(on_bridge.begin());
		}
					
		if (idx < n && truck[idx + 1] + cur_weight <= l)
		{
			cur_weight += truck[idx + 1];
			on_bridge.push_back(idx + 1);
			idx++;
		}

		for (auto ele : on_bridge)
			dist[ele]--;
	}
	cout << time;
}