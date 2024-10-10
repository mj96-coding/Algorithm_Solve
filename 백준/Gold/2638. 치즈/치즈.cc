#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <deque>

using namespace std;

int N, M;

int map[100][100];
int copy_map[100][100];

int visited[100][100];

int ret;
int cnt_ch;

struct Point
{
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };


void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				cnt_ch++;
			}
		}
	}
}

queue<Point> q;
void bfs()
{
	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next = { now.y + dy[i],now.x + dx[i] };

			if (next.y >= N || next.x >= M || next.y < 0 || next.x < 0) continue;
			if (visited[next.y][next.x] == 1) continue;

			if (map[next.y][next.x] == 1)
			{
				copy_map[next.y][next.x]++;
			}

			if (map[next.y][next.x] == 0)
			{
				visited[next.y][next.x] = 1;
				q.push(next);
			}
		}
	}
}


void solve()
{
	visited[0][0] = 1;
	q.push({ 0,0 });

	while (cnt_ch > 0)
	{
		bfs();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visited[i][j] == 0)
				{
					if (copy_map[i][j] >= 2)
					{
						cnt_ch--;
						map[i][j] = 0;

						visited[i][j] = 1;
						q.push({ i,j });
					}
				}
			}
		}

		ret++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();

	solve();

	cout << ret;

	return 0;
}
