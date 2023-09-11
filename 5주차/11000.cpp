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
    sort(lec.begin(), lec.end());
    pq.push(lec[0].second);
    for (int j = 1;  j < n; j++)
    {
        if (pq.top() <= lec[j].first)
        {
            pq.pop();
            pq.push(lec[j].second);
        }
        else   
            pq.push(lec[j].second);
    }
    cout << pq.size();

    return 0;
}