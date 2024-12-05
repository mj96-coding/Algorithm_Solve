#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N;

int tree[1000000];

int max_tree;

int M;

int ret;


void input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];

        max_tree = max(max_tree, tree[i]);
    }
}


long long getTree(int n)
{
    long long sum_tree = 0;

    for (int i = 0; i < N; i++)
    {
        if (tree[i] < n) continue;

        sum_tree += tree[i] - n;
    }

    return sum_tree;
}


void binarySearch()
{
    int st = 0;
    int en = max_tree;
    int mid = (st + en) / 2;

    while (st <= en)
    {
        mid = (st + en) / 2;

        long long tree_sum = getTree(mid);

        if (tree_sum >= M)
        {
            ret = mid;

            st = mid + 1;
        }
        else if (tree_sum < M)
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

    binarySearch();

    cout << ret;

    return 0;
}
