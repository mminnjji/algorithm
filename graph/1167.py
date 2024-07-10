import sys
from collections import deque
input = sys.stdin.readline

#1167 트리의 지름

# 전부 탐색하면서, max 를 업데이트 시켜주는게 좋은데
# 어떻게 저장을 해놔야 잘해놨다는 소문이 날지 모르겠음

# 탐색할 때 visited 변수를 둡시다

n = int(input())
tree = [[] for _ in range(n+1)]

for _ in range(n):
	line = list(map(int, input().split()))
	idx = 1
	while line[idx] != -1:
		tree[line[0]].append((line[idx], line[idx + 1]))
		idx += 2

visited = [-1] * (n + 1)
visited[1] = 0

def DFS(node, dist):
	for v, d in tree[node]:
		cal_dist = dist + d
		if visited[v] == -1:
			visited[v] = cal_dist
			DFS(v, cal_dist)
	
	return

DFS(1, 0)
tmp = [0, 0]

for i in range(1, len(visited)):
	if visited[i] > tmp[1]:
		tmp[1] = visited[i]
		tmp[0] = i

visited = [-1] * (n + 1)
visited[tmp[0]] = 0
DFS(tmp[0], 0)

print(max(visited))

