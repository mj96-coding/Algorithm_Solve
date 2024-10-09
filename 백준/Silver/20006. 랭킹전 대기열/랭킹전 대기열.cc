#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
1. 입장 가능방 없으면 새로운 방 생성 입장
2. 처음 플레이어 기준 +10,-10 입장가능
3. 입장 가능방 여러개 >> 먼저 생성된 방부터
4. 방 정원이 모두 차면 게임 시작
5. 방 시작되면 Started!
*/

using namespace std;

int p, m;

struct Man
{
	int l;
	string n;
};

// 방
vector<int> v[300];

// 플레이어 정보
Man man[300];

bool cmp(int a, int b)
{
	return man[a].n < man[b].n;
}

void input()
{
	cin >> p >> m;

	for (int i = 0; i < p; i++)
	{
		cin >> man[i].l >> man[i].n;
	}

	v[0].push_back(0);
}

// 시작   man idx, 현재까지 방 num
int num;
void simulation(int idx)
{
	bool canEnter = false;

	for (int i = 0; i <= num; i++)
	{
		if (v[i].size() < m)
		{
			int sub = abs(man[idx].l - man[v[i][0]].l);

			if (sub <= 10)
			{
				canEnter = true;
				v[i].push_back(idx);

				break;
			}
		}
	}

	if (canEnter == false)
	{
		v[num + 1].push_back(idx);
		num = num + 1;
	}
}

void solve()
{
	for (int i = 1; i < p; i++)
	{
		simulation(i);
	}
	for (int i = 0; i <= num; i++)
	{
		if (v[i].size() == m)
		{
			sort(v[i].begin(), v[i].end(), cmp);

			cout << "Started!\n";
			for (int j : v[i])
			{
				cout << man[j].l << " " << man[j].n << "\n";
			}
		}
		else if (v[i].size() < m)
		{
			sort(v[i].begin(), v[i].end(), cmp);

			cout << "Waiting!\n";
			for (int j : v[i])
			{
				cout << man[j].l << " " << man[j].n << "\n";
			}
		}
	}
}

int main()
{
	input();

	solve();

	return 0;
}