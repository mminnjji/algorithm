#바닥장식 1388
# dfs - 같은 인접한 나무판자 연결

n, m = map(int, input().split())
visit = [[0 for _ in range (m)]  for _ in range(n)]

suum = 0
round = []

for i in range(n):
	round.append(input())

def dfs(round, i, j):
	global suum
	global visit

	visit[i][j] = 1
	if round[i][j] == '-':
		if j != m - 1 and visit[i][j + 1] == 0 and round[i][j + 1] == '-':
			ddfs(round, i, j + 1)
		else:
			suum += 1
	elif round[i][j] == '|':
		if i != n - 1 and visit[i + 1][j] == 0 and round[i + 1][j] == '|':
			ddfs(round, i + 1, j)
		else:
			suum += 1

for i in range(n):
	for j in range(m):
		if visit[i][j] == 0:
			dfs(round, i, j)
		
print(suum)
