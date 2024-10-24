#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int N;
// 작년 순위 정보
int arr[501];  

int M;
// 그래프 (순위 관계를 저장)
vector<int> graph[501];     
// 각 노드의 선행 노드 개수
int prev1[501];             

// 최종 결과 저장
vector<int> result;  

// 확실한 순위
bool check = true;  
// 끝낸 노드 수
int cnt_fin;        


void init()
{
    for (int i = 0; i <= 500; i++)
    {
        graph[i].clear();
        prev1[i] = 0;
    }

    result.clear();

    check = true;
    cnt_fin = 0;
}


void input()
{
    cin >> N;

    // 작년 순위 입력받기
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    // 작년 순위기반 그래프
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            // i번째 값은 j번째 값들보다 앞에 나와야함(선행)
            graph[arr[i]].push_back(arr[j]);
            // j의 선행 갯수 추가
            prev1[arr[j]]++;
        }
    }

    cin >> M;

    // 순위가 바뀐 쌍을 입력
    // *** 이 부분이 중요함 
    // f와 t의 순위 관계 변경
    for (int i = 0; i < M; i++)
    {
        int f, t;
        cin >> f >> t;

        // f -> t 찾았는지 체크
        bool ok = false;

        // f가 t의 선행일 경우
        for (int j = 0; j < graph[f].size(); j++)
        {
            // t 값 찾음 (f가 t의 선행)
            if (graph[f][j] == t)
            {
                // f -> t 제거
                graph[f][j] = 0;
                // t 선행 갯수 감소
                prev1[t]--;
                // f -> t 에서 찾음
                ok = true;

                break;
            }
        }
        // f -> t 찾음
        if (ok == true)
        {
            // t -> f로 그래프 방향 바꿈 (선행 바뀜)
            graph[t].push_back(f);
            // f 선행 갯수 추가
            prev1[f]++;
        }
        else
        {
            // t -> f 에서 찾음
            for (int j = 0; j < graph[t].size(); j++)
            {
                if (graph[t][j] == f)
                {
                    // t -> f 제거
                    graph[t][j] = 0;
                    // f 선행 갯수 감소
                    prev1[f]--;

                    break;
                }
            }
            // f -> t로 변경
            graph[f].push_back(t);  
            // t 선행 갯수 추가
            prev1[t]++;
        }
    }
}


void bfs()
{
    queue<int> q;

    // 선행 노드가 없는 팀들을 큐에 넣기
    for (int i = 1; i <= N; i++)
    {
        if (prev1[i] == 0)
        {
            q.push(i);
        }
    }

    // 큐가 빌 때까지 위상 정렬 수행
    while (!q.empty())
    {
        // q에 2개 이상의 노드 있음 >> 순위 확실하지 않음
        if (q.size() > 1)
        {
            check = false;
        }

        int now = q.front();
        q.pop();

        // 순서대로 vector에 넣기
        result.push_back(now);
        // 완료한 노드 카운트
        cnt_fin++;

        // now와 연결된 노드들의 선행 노드 개수 갱신
        // 가능한 노드 push
        for (int next : graph[now])
        {
            // 그래프 제거할때 0처리 해서 넣은 조건
            // 없어도 문제되지 않을 가능성 높음
            // prev1[0] = 0 이므로 아래 조건문에 안걸리긴함
            if (next == 0) continue;

            // 선행 노드 완료 반영 (now가 next의 선행임)
            prev1[next]--;

            // 선행 노드 전부 완료인 경우
            if (prev1[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

void solve()
{
    bfs();

    // 끝낸 노드의 갯수가 N이 아니면 불가능한 경우
    if (cnt_fin != N)
    {
        cout << "IMPOSSIBLE" << "\n";
    }
    // 순위가 애매한 상태
    else if (check == false)
    {
        cout << "?" << "\n";
    }
    else
    {
        // 결과 순서대로 출력
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
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
    }

    return 0;
}
