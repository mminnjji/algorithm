#16236 아기 상어
#지나가기 가능한 칸 == 작은 물고기 + 빈 칸
# 도달 가능한 물고기 수에 따라서 이동이 달라짐

import sys
import heapq
from collections import deque

input = sys.stdin.readline

n = int(input())
baby = [2, 0, 0]
sea = []
for i in range(n):
    sea_n = list(map(int, input().split()))
    for j in range(n):
        sea.append(sea_n[j])

baby[1] = sea.index(9)
sea[baby[1]] = 0  # 아기 상어 위치를 빈 칸으로 설정

# 방향벡터: 상, 좌, 우, 하
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def bfs(start, size):
    visited = [False] * (n * n)
    queue = deque([(start, 0)])
    visited[start] = True
    candidates = []

    while queue:
        loc, dist = queue.popleft()
        x, y = divmod(loc, n)

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                nloc = nx * n + ny
                if not visited[nloc] and sea[nloc] <= size:
                    visited[nloc] = True
                    queue.append((nloc, dist + 1))
                    if 0 < sea[nloc] < size:
                        heapq.heappush(candidates, (dist + 1, nloc))

    return candidates

time_spent = 0

while True:
    candidates = bfs(baby[1], baby[0])
    if not candidates:
        break

    dist, new_loc = heapq.heappop(candidates)
    baby[1] = new_loc
    sea[baby[1]] = 0
    time_spent += dist
    baby[2] += 1

    if baby[2] == baby[0]:
        baby[0] += 1
        baby[2] = 0

print(time_spent)

