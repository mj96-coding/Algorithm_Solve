#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<int> num;

int ret;

void input() 
{
    cin >> N;
    num.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
}

void solve() 
{
    // 최소 힙을 사용하여 카드 묶음을 관리
    priority_queue<int, vector<int>, greater<int>> pq;

    // 카드 묶음들을 힙에 삽입
    for (int i = 0; i < N; i++)
    {
        pq.push(num[i]);
    }

    // 카드 묶음을 합쳐 나가며 최소 비교 횟수를 계산
    while (pq.size() > 1)
    {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int sum = first + second;
        ret += sum;

        pq.push(sum);
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
