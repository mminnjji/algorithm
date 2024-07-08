#11060 점프점프

# 칸에 대해서 -> 칸에다가 경우의 수를 적으면서 -> min 이면 업데이트 이런식

n = int(input())

miro = list(map(int, input().split()))

miro_v = [0 for _ in range(n)]

#점프 

if n == 1:
	print(0)
else:
	for i in range(n):
		if i == 0 :
			for j in range(i + 1, i + 1 + miro[i]):
				if j < n:
					miro_v[j] = 1
		elif miro_v[i] != 0:
			for j in range(i + 1, i + 1 + miro[i]):
				if j < n:
					if miro_v[j] > miro_v[i] + 1 or miro_v[j] == 0:
						miro_v[j] = miro_v[i] + 1

	if miro_v[n-1] == 0:
		print(-1)
	else:
		print(miro_v[n - 1])
