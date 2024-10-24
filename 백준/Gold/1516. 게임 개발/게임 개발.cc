#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N;  // 건물의 종류 수
vector<int> graph[501];  // 그래프 인접 리스트
int prework[501];  // 각 건물에 대한 선행 건물 수
int time_map[501];  // 각 건물을 짓는 데 걸리는 시간
int cost_map[501];  // 각 건물까지 걸리는 최소 시간

void init() {
    // 그래프 초기화 및 배열 초기화
    for (int i = 1; i <= 500; i++) {
        graph[i].clear();
        prework[i] = 0;
        cost_map[i] = 0;
    }
}

void input() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;  // 건물 짓는 시간 입력
        time_map[i] = t;

        while (true) {
            int pre;
            cin >> pre;
            if (pre == -1) break;  // -1로 입력 종료
            graph[pre].push_back(i);  // 선행 건물 -> 현재 건물
            prework[i]++;  // 선행 건물 수 증가
        }
    }
}

void bfs() {
    queue<int> q;

    // 선행 건물이 없는 건물들을 큐에 추가
    for (int i = 1; i <= N; i++) {
        if (prework[i] == 0) {
            cost_map[i] = time_map[i];
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : graph[now]) {
            // 현재 건물까지 걸린 시간 + 다음 건물의 짓는 시간 갱신
            cost_map[next] = max(cost_map[next], cost_map[now] + time_map[next]);
            prework[next]--;

            // 선행 건물이 모두 끝났을 때 큐에 추가
            if (prework[next] == 0) {
                q.push(next);
            }
        }
    }
}

void solve() {
    bfs();

    // 모든 건물의 최소 시간 출력
    for (int i = 1; i <= N; i++) {
        cout << cost_map[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();  // 초기화
    input();  // 입력 처리
    solve();  // 문제 해결

    return 0;
}
