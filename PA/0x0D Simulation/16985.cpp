// https://www.acmicpc.net/problem/16985

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

}

// ��� �� ���� ȸ���ϴ� ����Ǽ� 4 
// �� �̷� ���ռ� 4^5 = 1024���� ����Ǽ� ������ (for�� 0 ~ 1024 -> %4, /4�� 5�� �ݺ��Ͽ� �� ���� ȸ�� ����)
// 3���� BFS �� ������ ã��, ť empty ���� ��ã���� ������������.