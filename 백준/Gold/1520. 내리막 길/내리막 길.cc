#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>


using namespace std;

int M, N;
// 단순 dfs or bfs로 하면 무조건 시간 초과
int map[500][500];
// dp로 위치마다 경로 갯수 메모제이션
// dp[y][x] >> y,x로 가는 경로 갯수
int dp[500][500];

struct Point
{
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

int ret;


void input()
{
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	// dp -1로 초기화
	// 0으로 초기화하면 문제 생길 가능성 높음
	// 주위에 갈 경로가 없는경우?? (확인 필요)
	memset(dp, -1, sizeof(dp));

	// 초기값 0,0 시작점
	// 경로 1로 초기화
	// 다른곳에서 출발점으로 오는 경우는 없으므로
	dp[0][0] = 1;
}

// dfs로 탐색하면서 dp 갱신
// 도착점에서 역으로 출발 + 오르막
void dfs(Point now)
{
	// 이미 dp가 갱신된 경우
	if (dp[now.y][now.x] != -1)
	{
		return;
	}

	// 초기값 0 설정
	// 방문했는데 다른 경로를 찾기 전
	dp[now.y][now.x] = 0;

	for (int i = 0; i < 4; i++)
	{
		Point next = { now.y + dy[i],now.x + dx[i] };

		if (next.y >= M || next.x >= N || next.y < 0 || next.x < 0) continue;
		// 도착점 부터 출발함
		// 오르막 계산 (내리막+평지 continue)
		if (map[next.y][next.x] <= map[now.y][now.x]) continue;

		// 갱신 안된 지점일 경우
		if (dp[next.y][next.x] == -1)
		{
			// dfs 돌려서 dp값(경로 갯수) 갱신
			dfs(next);
		}

		// dp[now]에 dp[next]들의 값들 더해주기
		// next >> now로 가는 것이므로 next들의 경로를 다 더해주기
		dp[now.y][now.x] += dp[next.y][next.x];
	}

}


void solve()
{
	// 도착점부터 역으로 추적
	dfs({ M - 1,N - 1 });

	ret = dp[M - 1][N - 1];
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
