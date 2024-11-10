#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int T;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		int n, a, b;
		cin >> n >> a >> b;

		pair<int, int> loop = { 0, 0 };
		string s = "";
		bool res = false;

		for (int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			s += c;
		}

		pair<int, int> cur = { 0, 0 };
		while (true) 
		{
			bool brk = false;
			for (auto c : s)
			{
				if (c == 'N')
					cur.Y++;
				if (c == 'E')
					cur.X++;
				if (c == 'S')
					cur.Y--;
				if (c == 'W')
					cur.X--;

				if (cur.X == a && cur.Y == b)
				{
					res = true;
					brk = true;
				}
			}
			if (brk)
				break;
			if (cur.X == 0 && cur.Y == 0)
				break;
			if (cur.X > 20 || cur.Y > 20 || cur.X < -20 || cur.Y < -20)
				break;
		}

		if (res)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}