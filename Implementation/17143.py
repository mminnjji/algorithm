#17143 낚시왕

# 상어가 한마리 들어있을 수 있는 이차원 보드 - 상어는 각각 크기와 속도를 요소로 가짐 - 3차원 배열?
# 낚시왕은 한번에 한칸이동 + 마지막 칸에 도착하면 멈춤
# 가장 가까운 상어를 잡음 - 가장 0에 가까운 행에 있는 해당열의 상어
# 상어가 이동할 때 칸의 범위를 멋어난다면, 방향을 반대로
# 상어가 이동을 마친 후에는 상어가 두마리 이상 있을 수 있으나, 크기가 큰 상어가 남는다 - 나머지 상어를 모두 잡아 먹음
# 낚시왕이 잡은 상어 크기의 합?



def move_shark(board, R, C):
	newboard = [[[] for _ in range(C)] for _ in range(R)]
	for i in range(R):
		for j in range(C):
			if board[i][j] != []:
				if board[i][j][1] == 1:
					if i - board[i][j][0] >= 0 :
						if newboard[i - board[i][j][0]][j] == [] or newboard[i - board[i][j][0]][j][2] < board[i][j][2]:
							newboard[i - board[i][j][0]][j] = board[i][j]
					else :
						mod = (board[i][j][0] - i) % (R - 1)
						k = (board[i][j][0] - i) // (R - 1)
						if k % 2 :
							if newboard[R - mod - 1][j] == [] or newboard[R - mod - 1][j][2] < board[i][j][2]:
								newboard[R - mod - 1][j] = board[i][j]
						else :
							if newboard[mod][j] == [] or newboard[mod][j][2] < board[i][j][2]:
								newboard[mod][j] = board[i][j]
								newboard[mod][j][1] = 2
				elif board[i][j][1] == 2:
					if i + board[i][j][0] < R :
						if newboard[i + board[i][j][0]][j] == [] or newboard[i + board[i][j][0]][j][2] < board[i][j][2]:
							newboard[i + board[i][j][0]][j] = board[i][j]
					else :
						mod = (board[i][j][0] - R + i + 1) % (R - 1)
						k = (board[i][j][0] - R + i+ 1) // (R - 1)
						if k % 2 :
							if newboard[mod][j] == [] or newboard[mod][j][2] < board[i][j][2]:
								newboard[mod][j] = board[i][j]
						else :
							if newboard[R - mod - 1][j] == [] or newboard[R - mod - 1][j][2] < board[i][j][2]:
								newboard[R - mod - 1][j] = board[i][j]
								newboard[R - mod - 1][j][1] = 1
				elif board[i][j][1] == 4:
					if j - board[i][j][0] >= 0 :
						if newboard[i][j - board[i][j][0]] == [] or newboard[i][j - board[i][j][0]][2] < board[i][j][2]:
							newboard[i][j - board[i][j][0]] = board[i][j]
					else :
						mod = (board[i][j][0] - j) % (C - 1)
						k = (board[i][j][0] - j) // (C - 1)
						if k % 2:
							if newboard[i][C - mod - 1] == [] or newboard[i][C - mod - 1][2] < board[i][j][2]:
								newboard[i][C - mod - 1] = board[i][j]
						else :
							if newboard[i][mod] == [] or newboard[i][mod][2] < board[i][j][2]:
								newboard[i][mod] = board[i][j]
								newboard[i][mod][1] = 3
				elif board[i][j][1] == 3:
					if j + board[i][j][0] < C :
						if newboard[i][j + board[i][j][0]] == [] or newboard[i][j + board[i][j][0]][2] < board[i][j][2]:
							newboard[i][j + board[i][j][0]] = board[i][j]
					else :
						mod = (board[i][j][0] - C + j + 1) % (C - 1)
						k = (board[i][j][0] - C + j + 1) // (C - 1)
						if k % 2:
							if newboard[i][mod] == [] or newboard[i][mod][2] < board[i][j][2]:
								newboard[i][mod] = board[i][j]
						else :
							if newboard[i][C - mod - 1] == [] or newboard[i][C - mod - 1][2] < board[i][j][2]:
								newboard[i][C - mod - 1] = board[i][j]
								newboard[i][C - mod - 1][1] = 4
	return newboard

        

R,C,M = map(int, input().split())

# board의 칸이 리스트가 되려면 어떻게 해야할까,,

sum = 0
board = [[[] for _ in range(C)] for _ in range(R)]

for _ in range(M):
	a, b, c, d, e = map(int, input().split())
	board[a - 1][b - 1] = [c, d, e]

for j in range(C):
	for i in range(R):
		if board[i][j] != []:
			sum += board[i][j][2]
			board[i][j] = []
			break
	board = move_shark(board, R, C)
print(sum)
  