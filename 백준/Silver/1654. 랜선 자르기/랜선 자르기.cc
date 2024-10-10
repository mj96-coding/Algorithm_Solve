#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

int K, N;

long long total_len;

long long max_len = INT_MIN;

long long arr[10000];

long long ret;

void input()
{
    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        cin >> arr[i];
        total_len += arr[i];
        max_len = max(max_len, arr[i]);
    }
}


long long func(int n)
{
    long long cnt = 0;

    for (int i = 0; i < K; i++)
    {
        cnt += arr[i] / n;
    }

    return cnt;
}


void solve()
{
    long long st = 1;
    long long en = max_len;

    while (st <= en)
    {
        long long mid = (st + en) / 2;
        long long total = func(mid);

        if (total >= N)
        {
            ret = mid;
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
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

    cout << ret << "\n";

    return 0;
}
