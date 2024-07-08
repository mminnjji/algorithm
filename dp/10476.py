# 10476 좁디좁,, 은 미술관

#세로 n 줄, 가로로 2칸의 방 - 서로 연결되어 있는데, k 개의 방을 닫아야 함. 
#한쪽 끝의 두방 중의 하나 -> 다른쪽의 방하나로 나갈 수 있어야함
#가치와, 연결을 모두 고려해야함 - 판단해야하는 것 - min 일때 연결
# 연결되려면 이전노드의 i - 1이나 j - 1 이 고려되어야 할 것

n, k = map(int, input().split())

misul = [list(map(int, input().split())) for _ in range(n)]

# 방의 경우가 00 01 10 으로 주어질 수 있음
## 1: 00 -> 00 10 01 // 2: 01 -> 00 01 // 3: 10 -> 10 00
DP = [[[0] * n for _ in range(k)] for i in range(3)]


for i in range(n)

print(DP)

