#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>


using namespace std;

int N, M;

struct Edge
{
	int n;
	int cost;
};

struct cmp
{
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

vector<vector<Edge>> v;
vector<int> cost_map;

int ret;

int sn, en;

void input()
{
	cin >> N >> M;

	v.resize(N + 1);
	cost_map.assign(N + 1, INT_MAX);

	for (int i = 0; i < M; i++)
	{
		int f, t, c;
		cin >> f >> t >> c;

		v[f].push_back({ t,c });
	}
	
	cin >> sn >> en;
}


void dijkstra(Edge st)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	cost_map[st.n] = 0;
	pq.push({ st.n,cost_map[st.n] });

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (cost_map[now.n] < now.cost) continue;

		for (Edge next : v[now.n])
		{
			if (cost_map[next.n] <= now.cost + next.cost) continue;

			cost_map[next.n] = now.cost + next.cost;
			pq.push({ next.n,cost_map[next.n] });
		}
	}
}


void solve()
{
	dijkstra({ sn,0 });

	ret = cost_map[en];
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
