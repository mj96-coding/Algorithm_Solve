#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N;

int map[10][10];
int people[10];

// A지역구, B지역구
vector<int> groupA;
vector<int> groupB;

int ret = INT_MAX;

void init()
{
	ret = INT_MAX;
	groupA.clear();
	groupB.clear();
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> people[i];
	}

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		for (int j = 0; j < a; j++)
		{
			int b;
			cin >> b;
			b--;

			map[i][b] = 1;
		}
	}
}
// 지역구vector를 파라미터로
bool bfsCheck(vector<int>& group)
{
	if (group.size() == 0)
	{
		return false;
	}

	// 방문처리로 연결성 체크
	int visited[10] = { 0 };

	queue<int> q;
	visited[group[0]] = 1;
	q.push(group[0]);

	// cnt = 1부터(방문한 지역 갯수 체크)
	int cnt = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next : group)
		{
			if (visited[next] == 1) continue;
			if (map[now][next] == 0) continue;

			visited[next] = 1;
			q.push(next);
			cnt++;
		}
	}
	// 체크하기
	return cnt == group.size();
}

// 종료조건 잘보기
void simulation(int idx)
{
	// N개 분배 끝남
	if (idx == N)
	{
		// 0개인 지역구는 제외
		if (groupA.size() != 0 && groupB.size() != 0)
		{
			// 둘 다 연결성 통과
			if (bfsCheck(groupA) && bfsCheck(groupB))
			{
				int sumA = 0;
				int sumB = 0;
				// 각 지역구 인원 합계
				for (int i : groupA)
				{
					sumA += people[i];
				}
				for (int i : groupB)
				{
					sumB += people[i];
				}

				ret = min(ret, abs(sumA - sumB));
			}
		}
		// 놓치기 쉬움
		// 리턴해야함(지역을 둘 다 나눠줌)
		return;
	}

	//A에 넣어주거나 B에 넣어주거나
	groupA.push_back(idx);
	simulation(idx + 1);
	groupA.pop_back();

	groupB.push_back(idx);
	simulation(idx + 1);
	groupB.pop_back();
}

void solve()
{
	// idx 0부터 시작이므로 simulation(0)
	simulation(0);

	if (ret == INT_MAX)
	{
		ret = -1;
	}
}


int main()
{
	init();

	input();
	
	solve();

	cout << ret;

	return 0;
}