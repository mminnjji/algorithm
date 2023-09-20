#include <iostream>
#include <algorithm> // min
using namespace std;

int N, M, n = 1;
int map[51][51]; // 입력값 - 자동으로 -1로 초기화 불가능
int main() {
  scanf("%d %d", &N, &M);

  for(int i = 0; i <50; i++){
    for(int j = 0; j < 50; j++){
      map[i][j] = -1; // -1로 초기화
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%1d", &map[i][j]); // 숫자 1개씩 받기
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      for(int k = 1; k < min(N,M); k++){ // N이나 M중 작은것
        // if(map[i][j] == -1 || map[i+k][j] == -1 || map[i][j+k] == -1 || map[i+k][j+k] == -1){
        //   continue;
        // }
        if(i + k < N && j + k < M && map[i][j] == map[i+k][j] && map[i][j] == map[i][j+k] && map[i][j] == map[i+k][j+k]){
          // printf("%d %d %d\n", i, j, k);
          n = max(n, k+1);
        }
      }
    }
  }

  printf("%d", n * n);

  return 0;
}