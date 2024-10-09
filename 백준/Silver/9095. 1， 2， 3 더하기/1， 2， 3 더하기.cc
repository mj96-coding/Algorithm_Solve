#include <iostream>
#include <vector>

using namespace std;

int N;

void input()
{
    cin >> N;
}

int func(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    return func(n - 1) + func(n - 2) + func(n - 3);
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        input();

        cout << func(N) << "\n";
    }

    return 0;
}
