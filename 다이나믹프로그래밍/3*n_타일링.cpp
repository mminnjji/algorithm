#include <string>

using namespace std;

unsigned long long sum(unsigned long long wall[], int i)
{
    unsigned long long sum = 0;

    for (int j = 0; j < i; j++)
    {
        sum += wall[j];
    }
    return sum;
}

unsigned long long solution(int n) {
    unsigned long long wall[5001];
    unsigned long long mod;
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
            wall[i] = (wall[i - 2] * 3 + sum(wall, i - 2) * 2 + 2) % 1000000007;
        }
    }
    mod = wall[n];
    return (mod);
}