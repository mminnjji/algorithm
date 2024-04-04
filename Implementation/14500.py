# 폴리오미노 = 1*1 정사각형 연결된 것
# 4개 이어붙인 것 = 테트로미노
# 5개의 테트로미노를 놓아서 가장 큰 합
# 연결되어있는 4개의 칸의 합이 제일 큰 것 선택?
# 브루트포스

n,m = map(int, input().split())

board = []
for _ in range(n):
	board.append(list(map(int,input().split())))

# 모든 칸에서, 인덱스가 가능할때, 이칸을 가장 앞선순번으로 두는 녀석이라면, 중복검사하지 않게 됨

max = 0
for i in range(n):
	for j in range(m):
		if i + 3 < n:
			sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j]
			if sum > max:
				max = sum
		if j + 3 < m:
			sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3]
			if sum > max:
				max = sum
		if j + 2 < m and i + 1 < n:
			sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]
			if sum > max:
				max = sum
		if j + 1 < m and i + 2 < n:
			sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1]
			if sum > max:
				max = sum
		if j + 1 < m and i + 1 < n:
			sum = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1]
			if sum > max:
				max = sum
		
		####################################
		if j + 1 < m and j - 1 >= 0 and i + 1 < n:
			sum = board[i][j] + board[i][j + 1] + board[i + 1][j - 1] + board[i + 1][j]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1]
			if sum > max:
				max = sum
		if j - 2 >= 0 and i + 1 < n:
			sum = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 1][j - 2]
			if sum > max:
				max = sum

		if j - 1 >= 0 and i + 2 < n:
			sum = board[i][j] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 2][j]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1]
			if sum > max:
				max = sum
			sum = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1]
			if sum > max:
				max = sum
		
print(max)
