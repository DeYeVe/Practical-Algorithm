// https://www.acmicpc.net/problem/16985

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

}

// 모든 판 각각 회전하는 경우의수 4 
// 총 미로 조합수 4^5 = 1024개의 경우의수 따진다 (for문 0 ~ 1024 -> %4, /4를 5번 반복하여 각 층의 회전 적용)
// 3차원 BFS 로 도착점 찾기, 큐 empty 까지 못찾으면 존재하지않음.