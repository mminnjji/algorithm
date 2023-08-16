#include <iostream>
#include <vector>

using namespace std;

void paintHouse(int house[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        house[i + 1][0] = house[i][1] < house[i][2] ? house[i][1] + house[i + 1][0] : house[i][2] + house[i + 1][0];
        house[i + 1][1] = house[i][0] < house[i][2] ? house[i][0] + house[i + 1][1] : house[i][2] + house[i + 1][1];
        house[i + 1][2] = house[i][0] < house[i][1] ? house[i][0] + house[i + 1][2] : house[i][1] + house[i + 1][2];
    }
    if (house[n - 1][0] < house[n - 1][1])
    {
        if (house[n - 1][0] < house[n - 1][2])
            cout << house[n - 1][0];
        else
            cout << house[n - 1][2];
    }
    else
    {
        if (house[n - 1][1] < house[n - 1][2])
            cout << house[n - 1][1];
        else
            cout << house[n - 1][2];
    }
}

int main() 
{
    int n;

    cin >> n;
    int house[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }
    paintHouse(house, n);
    return 0;
}
