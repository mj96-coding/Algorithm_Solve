#include <iostream>

using namespace std;

int N, M;

int map[50][50];

struct Point 
{
    int y;
    int x;
};

Point st;
int dir;
int ret;

// 북 동 남 서 (시계방향)
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void input()
{
    cin >> N >> M;

    cin >> st.y >> st.x;
    cin >> dir;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> map[i][j];
        }
    }
}

void simulation(Point now, int now_dir)
{
    if (map[now.y][now.x] == 0)
    {
        map[now.y][now.x] = 2;
        ret++;
    }

    bool canClean = false;

    for (int i = 0; i < 4; i++) 
    {
        int next_dir = (now_dir + 3 - i) % 4;

        Point next = { now.y + dy[next_dir], now.x + dx[next_dir] };

        if (next.y >= N || next.x >= M || next.y < 0 || next.x < 0) continue;
        if (map[next.y][next.x] == 1 || map[next.y][next.x] == 2) continue;

        simulation(next, next_dir);
        canClean = true;

        break;

    }

    if (!canClean)
    {
        Point next = { now.y - dy[now_dir], now.x - dx[now_dir] }; // 후진

        if (next.y >= N || next.x >= M || next.y < 0 || next.x < 0)
        {
            return;
        }
        if (map[next.y][next.x] == 1)
        {
            return;
        }
        
        simulation(next, now_dir);   
    }
}

int main()
{
    input();

    simulation(st, dir);

    cout << ret;

    return 0;
}
