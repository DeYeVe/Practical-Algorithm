//https://www.acmicpc.net/problem/6549

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		ll ans = 0;


		stack<pair<ll, ll>> S;

		for (int i = 0; i < n; ++i)
		{
			ll h;
			cin >> h;
			ll idx = i;

			while (!S.empty() && S.top().first >= h)
			{
				ans = max(ans, (i - S.top().second) * S.top().first);
				idx = S.top().second;
				S.pop();
			}

			S.push({ h, idx });
		}

		while (!S.empty())
		{
			ans = max(ans, (n - S.top().second) * S.top().first);
			S.pop();
		}


		cout << ans << '\n';
	}
}