import copy

n, m, k = map(int, input().split())

init_A = [[5] * n for _ in range(n)]
A = []
# 양분의 정보
for _ in range(n):
	A.append(list(map(int, input().split())))

# 땅의 정보 - 나무의 위치, 나이
land = [[[] for _ in range(n)] for _ in range(n)]


# 나무 위치에 나무 삽입
for _ in range(m):
	x, y, z = map(int, input().split())
	land[x - 1][y - 1].append(z)

orig_A = copy.deepcopy(A)


#봄 - 양분먹거나 / 죽거나
#여름 - 죽은 나무 -> 양분 - 나이 /2 가 해당칸의 양분
#가을 - 나무 번식 - 5배수의 나이 나무 - 인접 8칸에 1의 나무 생김
#겨울 - 땅에 양분 추가 + 양분 양은 입력

#3차원 리스트를 쓰면, 그 각각의 2차원 배열에 담은 값에 대해서 그 안에 들어있는 나무의 정보도 참조할 수 있음


for i in range(k):

	#봄 + 여름
	if i == 0:
		use_A = init_A
	for j in range(n):
		for h in range(n):
			# 어린 나무부터 양분 먹음
			land[j][h].sort()
			tmp = len(land[j][h])
			rest = 0
			for l in range(len(land[j][h])):
				if use_A[j][h] >= land[j][h][l]:
					use_A[j][h] -= land[j][h][l] # 나이만큼 양분 먹음
					land[j][h][l] += 1 # 나이 1 증가
				else:
					# 양분이 부족한 경우 남은 나무의 나이 모두 더하고, 나무 제거하기
					for u in range(l, len(land[j][h])):
						use_A[j][h] += land[j][h][u] // 2
					land[j][h] = land[j][h][:l]
					break
	# 가을
	# 인접 8칸에 나이가 1인 나무 생성
	for j in range(n):
		for h in range(n):
			for l in range(len(land[j][h])):
				if land[j][h][l] % 5 == 0:
					if j > 0:
						if h > 0:
							land[j - 1][h - 1].append(1)
						if h < n - 1:
							land[j - 1][h + 1].append(1)
						land[j - 1][h].append(1)
					if j < n - 1:
						if h > 0:
							land[j + 1][h - 1].append(1)
						if h < n - 1:
							land[j + 1][h + 1].append(1)
						land[j + 1][h].append(1)
					if h > 0:
						land[j][h - 1].append(1)
					if h < n - 1:
						land[j][h + 1].append(1)
			use_A[j][h] += orig_A[j][h]

sum = 0
for i in range(n):
	for j in range(n):
		sum += len(land[i][j])

print(sum)

