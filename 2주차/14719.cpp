#include <iostream>
#include <vector>

using namespace std;

void checkWall(vector<int> wall)
{
    // 물이 고이는 처음 벽, 마지막 벽을 기준으로하여 얼만큼 고이는지 판별
    // 고로, 큰 벽 두개를 만나면 sum에 합계시키고, 그 뒤로 이어감
    int first, idx, sum;
    first = wall[0];
    idx = 1;
    sum = 0;

    for (int i = 1; i < wall.size(); i++)
    {
        if (wall[i] >= first)
        {
            for (int j = idx; j < i; j++)
            {
                sum += first - wall[j];
            }
            first = wall[i];
            idx = i + 1;
        }
    }
    first = wall[wall.size() - 1];
    idx = wall.size() - 2;
    for (int i = wall.size() - 1; i >= 0; i--)
    {
        if (wall[i] > first)
        {
            for (int j = idx; j > i; j--)
            {
                sum += first - wall[j];
            }
            first = wall[i];
            idx = i - 1;
        }
    }
    cout << sum;
}

int main() 
{
    int width, height, tmp; // width, height, 벽의 높이를 담는 변수 tmp
    vector<int> wall;

    cin >> height >> width;
    for (int i = 0; i < width; i++)
    {
        cin >> tmp;
        wall.push_back(tmp);
    }
    checkWall(wall);
    return 0;
}
