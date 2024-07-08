import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

N = int(input())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def DFS(x, y):
    for m in range(4):
        nx = x + dx[m]
        ny = y + dy[m]
        if (0 <= nx < H) and (0 <= ny < W) and not issheep[nx][ny] and farm[nx][ny] == '#':
            issheep[nx][ny] = True
            DFS(nx, ny)

while N:
	count = 0
	farm = []

	H, W = map(int, input().split())
	issheep = [[False] * W for _ in range(H)]
	for i in range(H):
		farm.append(input())

	for i in range(H):
		for j in range(W):
			if farm[i][j] == '#' and not issheep[i][j]:
				count += 1
				issheep[i][j] = True
				DFS(i, j)
				
	N -= 1
	print(count)


	