//https://www.acmicpc.net/problem/2960

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;


	bool D[1001] = { false, };

	int mn = 2;
	int cnt = 0;

	for (int i = 2; i<= N; i++)
		for(int j = i; j <= N; j+=i)
			if (!D[j])
			{
				D[j] = true;
				cnt++;
				if (cnt == K)
				{
					cout << j;
					return 0;
				}
			}
}