#include <iostream>

using namespace std;

int sum(int wall[], int i)
{
    int sum = 0;

    for (int j = 0; j < i; j++)
    {
        sum += wall[j];
    }
    return sum;
}

int main()
{
    int n;
    int wall[31];

    cin >> n;
    wall[0] = 0;
    wall[1] = 0;
    wall[3] = 0;
    wall[2] = 3;
    for (int i = 4; i <= n; i++)
    {
        if (i % 2 == 1)
            wall[i] = 0;
        else
        {
            wall[i] = wall[i - 2] * 3 + sum(wall, i - 2) * 2 + 2;
        }
    }
    cout << wall[n];
}