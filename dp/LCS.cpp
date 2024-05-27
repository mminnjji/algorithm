/* LCS 알고리즘
스트링 X, Y 가 있을 때
1) 길이가 0이라면 종료
2) 끝이 같다면 LCS 라고 판단
3) 같지 않다면, 이전배열 (c[i - 1, j] c[i, j - 1]) 중 큰 배열 기준 다시 탐색

다이나믹 프로그래밍 원리로 미리 하위 문제에 대해 세팅 해놓고, 대소비교의 편의를 위해 탐색 방향을 지정함
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//저장된배열 기준 LCS 파악
void Print_LCS(vector<vector<string>> b, string X, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == "leftup") {
        Print_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == "up") {
        Print_LCS(b, X, i - 1, j);
    } else {
        Print_LCS(b, X, i, j - 1);
    }
}

int LCS_Length(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // 1 ~ m 번째 인덱스까지 저장하는 배열 c, b 초기화
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<string>> b(m + 1, vector<string>(n + 1, ""));

    // 하위단계부터 계산하면서 LCS 길이 계싼
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = "leftup";
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = "up";
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = "left";
            }
        }
    }

    // 길이가 m, n 일때의 LCS 를 역추적
    Print_LCS(b, X, m, n);
    cout << endl;

    return c[m][n];
}

int main() {
    string X, Y;
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;
    cout << "Length of LCS: " << LCS_Length(X, Y) << endl;
    return 0;
}


