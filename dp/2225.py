#2225 합분해

# 각 수에다가.. 그 수가 되는 경우의 수를 저장해놓는다면 가능
# 순서가 바뀐 경우는 다른 경우라는게 ㄹㅇ 극악무도 그자체

n, k = map(int, input().split())

#? 0 ~ N까지의 정수인게 개오바같음
#k 가 유동적이라 어렵..어려운데?
#k를 기준으로 n까지의 배열을 만들면서 다프

DP = [[0] * (k+1) for _ in range(n + 1)]
DP[0][0] = 1
for i in range(n + 1):
	for j in range(1, k+1):
		DP[i][j] = DP[i - 1][j] + DP[i][j - 1]

print(DP[n][k] % 1000000000)