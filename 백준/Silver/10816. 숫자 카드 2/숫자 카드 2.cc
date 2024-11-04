#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int sang[500000];
int dat1[20000001];

int num[500000];

int ret;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> sang[i];
		dat1[sang[i] + 10000001]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num[i];
	}
}


void solve()
{
	for (int i = 0; i < M; i++)
	{
		cout << dat1[num[i] + 10000001] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	solve();

	return 0;
}

