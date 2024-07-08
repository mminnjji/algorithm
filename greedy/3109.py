import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
dx = [-1, 0, 1]

R, C = map(int, input().split())
bread = [list(input().strip()) for _ in range(R)]
visited = [[0 for _ in range(C)] for l in range(R)]

def DFS(x, y):
	global found_path
	found_path = False
	if found_path:
		return False
	if y == C - 1:
		found_path = True
		return True
	for i in range(3):
		nx = x + dx[i]
		ny = y + 1
		if 0 <= nx < R and 0 <= ny < C:
			if bread[nx][ny] == '.' and visited[nx][ny] == 0:
				visited[nx][ny] = 1
				if DFS(nx, ny):
					return True
				visited[nx][ny] = 0
	return False

count = 0
for i in range(R):
    if bread[i][0] == '.':  # 시작점이 유효한지 확인
        visited[i][0] = 1
        if DFS(i, 0):
            count += 1

print(count)
