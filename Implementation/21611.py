#21611 마법사 상어와 블리자드

#블리자드
#거리와 방향의 모든 구슬 파괴 

#구슬이 없어진 자리 - 뒤에서 부터 채움

#그냥 배열로 나타내는 것 = 상어와 구슬의 리스트
#계산 - 배열의 인덱스를 2차원으로 나타냈을 때 어디일까
#폭발하는 구슬 = 같은구슬 4개 이상 연속 - 걍 폭발 - 인덱스끼리 비교
# 블리자드 -> 구슬이동 -> 구슬폭발 -> 구슬이동
# 구슬이동 멈춤 -> 구슬 변화 -> 구슬 그룹 -> 갯수/번호 기준 구슬 그룹을 갯수+번호의 두개의 요소를 갖는 배열로 변화시킴
# 칸 넘치면 사라짐 -> 이때 구슬 폭발 없음

# 상어 배열로 변환

explode = [0, 0, 0]
getbomb = 0

def bomb(arr):
	global explode
	global getbomb

	getbomb = 0
	for i in range(1, len(arr) - 3):
		if arr[i] != 0 and arr[i] == arr[i + 1] == arr[i + 2] == arr[i + 3]:
			getbomb = 1
			tmp = arr[i]
			j = i
			while arr[j] == tmp:
				arr[j] = 0
				explode[tmp - 1] += 1
				j += 1
				if (j >= len(arr)):
					break
	return arr

def erase_zero(arr):
	global getbomb

	newarr = []
	for i in range(len(arr)):
		if arr[i] != 0 or i == 0:
			newarr.append(arr[i])
	new2arr = bomb(newarr)
	while getbomb:
		newarr = erase_zero(new2arr)
		new2arr = bomb(newarr)
	return new2arr

def set_arr(arr):
	newarr = []

	i = 1
	while i < len(arr):
		count = 0
		tmp = arr[i]
		while i < len(arr) and arr[i] == tmp:
			count += 1
			i += 1
		newarr.append(count)
		newarr.append(tmp)
	return newarr
		



def make_board(arr, n):
    board = [[0] * n for _ in range(n)]  # n x n 크기의 모든 요소가 0인 배열을 생성합니다.
    x = int(n / 2)
    count = 1
    idx = 0

    # 상어의 이동 경로에 따라 arr의 요소를 board에 다시 배치합니다.
    while count <= int(n / 2):
        for i in range(count * 2):
            if idx < len(arr):
                board[x + i - count + 1][x - count] = arr[idx]
                idx += 1
        for i in range(count * 2):
            if idx < len(arr):
                board[x + count][x + i - count + 1] = arr[idx]
                idx += 1
        for i in range(count * 2):
            if idx < len(arr):
                board[x - i + count - 1][x + count] = arr[idx]
                idx += 1
        for i in range(count * 2):
            if idx < len(arr):
                board[x - count][x - i + count - 1] = arr[idx]
                idx += 1
        count += 1

    return board


def make_shark(board,n):
	arr = []
	arr.append(board[int(n/2)][int(n/2)])

	count = 1
	x = int(n / 2)
	while count <= int(n / 2):
		for i in range(count * 2):
			arr.append(board[x + i - count + 1][x - count])
		for i in range(count * 2):
			arr.append(board[x + count][x + i - count + 1])
		for i in range(count * 2):
			arr.append(board[x - i + count - 1][x + count])
		for i in range(count * 2):
			arr.append(board[x - count][x - i + count - 1])
		count += 1
	return arr


#구.폭할때의 갯수

n, num = map(int,input().split())

# 일단 보드를 받고 -> 상어배열로 변환
board = []
for _ in range(n):
	board.append(list(map(int, input().split())))

x = int(n/2)
for i in range(num):
	d, s = map(int, input().split())
	for j in range(s):
		if d == 1:
			board[x- j - 1][x] = 0
		elif d == 2:
			board[x + j + 1][x] = 0
		elif d == 3:
			board[x][x - j - 1] = 0
		elif d == 4:
			board[x][x + j + 1] = 0
	arr = make_shark(board, n)
	arr = erase_zero(arr)
	arr = set_arr(arr)
	board = make_board(arr, n)
	
print(1 * explode[0] + 2 * explode[1] + 3 * explode[2])
		