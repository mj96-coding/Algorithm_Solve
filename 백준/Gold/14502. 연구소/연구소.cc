#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>

/*
1. 벽(1) >> visited = 1 처리
2. 바이러스(2) >> bfs로 확산 체크
3. 시작점 2 && visited = 0
4. 벽 3개 설치 >> map = 0인 곳 중 3개 조합으로 뽑기 파라미터 (idx, lev)
5.
*/

using namespace std;

int N, M;

int map[8][8];
int copy_map[8][8];
int visited[8][8];

struct Point
{
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

int ret;
int safe;
vector<Point> canWall;
Point wall[3];

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				canWall.push_back({ i,j });
			}
		}
	}

	memcpy(copy_map, map, sizeof(map));
}

void bfs()
{
	queue<Point> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2 && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next = { now.y + dy[i],now.x + dx[i] };

			if (next.y >= N || next.x >= M || next.y < 0 || next.x < 0) continue;
			if (visited[next.y][next.x] == 1) continue;
			if (map[next.y][next.x] == 1) continue;

			visited[next.y][next.x] = 1;
			q.push(next);
		}
	}
}

void solve()
{
	safe = 0;
	// bfs할때마다 방문 초기화
	memset(visited, 0, sizeof(visited));

	// map 원본 유지
	memcpy(map, copy_map, sizeof(copy_map));

	for (int i = 0; i < 3; i++)
	{
		map[wall[i].y][wall[i].x] = 1;
	}

	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0 && map[i][j] == 0)
			{
				safe++;
			}
		}
	}

	ret = max(ret, safe);
}

// 벽 3개 설치하는 경우의 수 + bfs 영역 체크
void addWall(int idx, int lev)
{
	// 3개 고름 + map에 추가
	// solve() 로직 추가
	if (lev == 3)
	{
		solve();

		return;
	}

	// i = idx부터 시작! (조합 / 오름차순)
	for (int i = idx; i < canWall.size(); i++)
	{
		wall[lev] = canWall[i];
		// 파라미터 i + 1로 설정 (조합이므로 i로 하면 중복이됨)
		addWall(i + 1, lev + 1);
	}
}

int main()
{
	input();

	addWall(0, 0);

	cout << ret;

	return 0;
}