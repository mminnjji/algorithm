#16953 A->B

# 연산 A 는 2로 곱하는 것 / 연산 B 는 n * 10 + 1 이 되는 것 
# 곱하여 하는 것은 어떤 것이 정답인지 찾지 못할 확률이 매우 높음
# 1이 들어간 항목일 때 -> 1이 붙은 것
# 1이 아닌 홀수의 경우 만들어 질 수 없음 -> -1

init, res = map(int, input().split())

count = 0
flag =0
while init != res:
	count += 1
	tmp = res
	if res % 10 == 1:
		res = res // 10
	elif res % 2 == 0:
		res = res // 2
	
	if tmp == res:
		print(-1)
		flag = 1
		break
if not flag:
	print(count + 1)