#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N;

int arr[1000];
int dp[1000];

deque<int> path[1000];

int ret;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

int max_idx = -1;

void func()
{
    // i 끝점
    for (int i = 0; i < N; i++)
    {
        // 끝점 포함 길이 초기화
        dp[i] = 1;
        int idx = -1;

        for (int j = 0; j < i; j++)
        {
            // 작은값 찾음
            if (arr[i] > arr[j])
            {
                // j가 부분수열 바로 앞일 때 결과값 비교 최대 갱신
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    idx = j;
                }
            }
        }

        if (idx != -1)
        {
            for (int k : path[idx])
            {
                path[i].push_back(k);
            }
        }

        path[i].push_back(arr[i]);

        if (ret < dp[i])
        {
            ret = dp[i];
            max_idx = i;
        }
    }
}


void solve()
{
    func();

    cout << ret << "\n";

    for (int i : path[max_idx])
    {
        cout << i << " ";
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
