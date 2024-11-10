#include <bits/stdc++.h>
using namespace std;

int T;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		int n, m, v;
		cin >> n >> m >> v;
		vector<int> vec;
		int ed = 0;
		int sum = 0;
		int cnt = 0;
		bool brk = false;
		vector<int> D; // 부분합
		int tot = 0; // 총 케이크 크기

		for (int i = 0; i < n; i++)
		{
			int in;
			cin >> in;
			vec.push_back(in);
		}

		for (int st = 0; st < n; st++)
		{
			while (sum < v && ed < n)
			{
				sum += ed;
				ed++;
			}
			if (ed < n)
			{
				cnt++;
			}
			else
			{
				if (cnt < m)
					brk = true;
			}
			if (brk)
				break;
		}
		if (brk) 
		{
			cout << -1 << "\n";
			continue;
		}
	}
}