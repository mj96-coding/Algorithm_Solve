#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<int> num;

int ret;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

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
    priority_queue<int, vector<int>, cmp> pq;

    for (int i = 0; i < N; i++)
    {
        pq.push(num[i]);
    }

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