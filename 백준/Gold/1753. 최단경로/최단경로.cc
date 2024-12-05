#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int V, E, K;

// 도착점, 코스트
struct Info
{
    int n;
    int cost;
};

// 코스트 기준 오름차순
struct cmp
{
    bool operator() (Info a, Info b)
    {
        return a.cost > b.cost;
    }
};

// 연결, 코스트 저장 2차 벡터
vector<vector<Info>> v;

// 최단거리 저장 벡터
vector<int> cost_map;

void input()
{
    cin >> V >> E >> K;
    // 벡터 사이즈 설정
    v.resize(V + 1);
    cost_map.assign(V + 1, INT_MAX); // 벡터 크기 및 초기화

    for (int i = 0; i < E; i++)
    {
        int f, t, c;
        cin >> f >> t >> c;

        v[f].push_back({ t,c });
    }
}

void dijkstra(Info st)
{
    // pq 안에 구조 익숙해지기
    priority_queue<Info, vector<Info>, cmp> pq;
    // 시작점 코스트 0 (경우에 따라 다름)
    cost_map[st.n] = 0;
    pq.push({ st.n, cost_map[st.n] });

    while (!pq.empty())
    {
        Info now = pq.top();
        pq.pop();

        if (cost_map[now.n] < now.cost) continue;

        for (Info next : v[now.n])
        {
            if (cost_map[next.n] <= cost_map[now.n] + next.cost) continue;

            cost_map[next.n] = cost_map[now.n] + next.cost;
            pq.push({ next.n, cost_map[next.n] });
        }
    }
}

void solve()
{
    dijkstra({ K,0 });

    for (int i = 1; i <= V; i++)
    {
        if (cost_map[i] == INT_MAX)
        {
            cout << "INF\n";
        }
        else
        {
            cout << cost_map[i] << "\n";
        }
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
