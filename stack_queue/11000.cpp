#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> lec;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int n;
    int a, b;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        lec.push_back(make_pair(a, b));
    }
    sort(lec.begin(), lec.end()); // start 기준으로 정렬
    pq.push(lec[0].second); // 첫번째로 시작하는 class의 end값을 기준으로
    for (int j = 1;  j < n; j++)
    {
        if (pq.top() <= lec[j].first) // second 와 first 값 비교
        {
            pq.pop();
            pq.push(lec[j].second); // 연결될 수 있으면 pop하고 넣고,
        }
        else   
            pq.push(lec[j].second); // 연결할 수 없으면 그냥 넣음.
    }
    cout << pq.size();

    return 0;
}