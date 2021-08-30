// https://www.acmicpc.net/problem/1697

#include <bits/stdc++.h>
using namespace std;

int dst[100002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(dst, dst + 100001, -1);

	int n, k;
	cin >> n >> k;

	dst[n] = 0;
	queue<int> Q;
	Q.push(n);

	while (dst[k] == -1)
	{
		int cur = Q.front();
		Q.pop();
		for (int nxt : { cur - 1, cur + 1, cur * 2 })
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			if (dst[nxt] >= 0)
				continue;
			dst[nxt] = dst[cur] + 1;
			Q.push(nxt);
		}		
	}
	cout << dst[k];
}