# 14503 로봇청소기

# 0일때 빈칸 1일때 벽

def check_allclean(board):
	for i in range(len(board)):
		for j in range(len(board[i])):
			if board[i][j] == 0:
				return 1
	return 0

row,col = map(int, input().split()) 
x, y, dir = map(int, input().split())

board = []
for _ in range(row):
	board.append(input().split())

board = [[int(element) for element in r] for r in board]

count = 0
while True :
	if check_allclean(board):
		# 현재 위치 청소
		if board[x][y] == 0:
			board[x][y] = 2
			count += 1
		# 빈칸이 없을 때
		if board[x + 1][y] != 0 and board[x - 1][y] != 0 and board[x][y + 1] != 0 and board[x][y - 1] != 0 :
			if dir == 0:
				x = x + 1
			elif dir == 1:
				y = y - 1
			elif dir == 2:
				x = x - 1
			elif dir == 3:
				y = y + 1
			if board[x][y] == 1:
				break
		else :
			flag = 0
			while True :
				dir = dir - 1
				if dir == -1 :
					dir = 3
				elif dir == 4 :
					dir = 0
				if dir == 0 and board[x - 1][y] == 0:
					x = x - 1
					break
				elif dir == 1 and board[x][y + 1] == 0:
					y = y + 1
					break
				elif dir == 2 and board[x + 1][y] == 0:
					x = x + 1
					break
				elif dir == 3 and board[x][y - 1] == 0:
					y = y - 1
					break
	else :
		break

print(count)
