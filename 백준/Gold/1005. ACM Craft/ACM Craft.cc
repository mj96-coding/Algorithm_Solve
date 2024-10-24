#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>


using namespace std;

int N, K;
int W;

int prework[1001];

int time_map[1001];
int cost_map[1001];

int ret;

struct Edge
{
	int n;
	int cost;
};

vector<Edge> graph[1001];

void init()
{
	ret = 0;
	for (int i = 0; i < 1001; i++)
	{
		graph[i].clear();
		prework[i] = 0;
		cost_map[i] = -1;
	}
}


void input()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> time_map[i];
	}

	for (int i = 0; i < K; i++)
	{
		int f, t;
		cin >> f >> t;

		graph[f].push_back({ t,time_map[t] });
		prework[t]++;
	}

	cin >> W;
}


void bfs()
{
	queue<Edge> q;

	for (int i = 1; i <= N; i++)
	{
		if (prework[i] == 0)
		{
			cost_map[i] = time_map[i];
			q.push({ i,cost_map[i] });
		}
	}


	while (!q.empty())
	{
		Edge now = q.front();
		q.pop();

		if (now.n == W)
		{
			ret = max(ret, now.cost);
		}

		for (Edge next : graph[now.n])
		{
			prework[next.n]--;

			if (cost_map[next.n] < cost_map[now.n] + time_map[next.n])
			{
				cost_map[next.n] = cost_map[now.n] + time_map[next.n];
			}

			if (prework[next.n] == 0)
			{
				q.push({ next.n,cost_map[next.n] });
			}
		}
	}
}


void solve()
{
	bfs();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();

		input();

		solve();

		cout << ret << "\n";
	}

	return 0;
}
