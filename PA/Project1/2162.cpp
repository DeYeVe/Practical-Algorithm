// https://www.acmicpc.net/problem/2162

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int N;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	pair<pair<int, int>, pair<int, int>> lines[3000];
	int root[3000] = { -1, };

	int groups = 0;
	int max = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> lines[i].X.X >> lines[i].X.Y >> lines[i].Y.X >> lines[i].Y.Y;
	}
	auto ccw = [](int& ax, int& ay, int& bx, int& by, int& cx, int& cy)
		{
			int s = (ay - by) * (bx * cx) - (ax - bx) * (by - cy);
			return s;
		};

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{

			//교차 판정
			int ccw1 = ccw(lines[i].X.X, lines[i].X.Y, lines[i].Y.X, lines[i].Y.Y, lines[j].X.X, lines[j].X.Y) *
				ccw(lines[i].X.X, lines[i].X.Y, lines[i].Y.X, lines[i].Y.Y, lines[j].Y.X, lines[j].Y.Y);
			int ccw2 = ccw(lines[j].X.X, lines[j].X.Y, lines[j].Y.X, lines[j].Y.Y, lines[i].X.X, lines[i].X.Y) *
				ccw(lines[j].X.X, lines[j].X.Y, lines[j].Y.X, lines[j].Y.Y, lines[i].Y.X, lines[i].Y.Y);


			//CCW의 값이 모두 0이 나와버리는 경우

			// 판정후 union find
		}
}