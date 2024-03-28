# 1339 단어수학
# 단어 수가 긴 녀석을 기준으로, 높은 위치에 있는 알파벳이 큰 수로 바뀐다고 가정
# 알파벳별로 곱해지는 수를 계속 누적해서 저장해줌
# 자릿수 -> 10의 자리수로 바꿔줘서 진헹



def find_alpha(alpha, c):
	for i in range(len(alpha)):
		if c == alpha[i][0]:
			return i
	return -1


def get_int_size(size, idx):
	newi = size - idx - 1
	res = 1
	for i in range(newi):
		res = res * 10
		i += 1
	return res

n = int(input())
word = []
for i in range(n):
	word.append(list(input()))

alpha = []
# 리스트 안에 있으면 더해주고 없으면 append

for i in range(n):
	for j in range(len(word[i])):
		idx = find_alpha(alpha, word[i][j])
		if idx != -1:
			alpha[idx][1] += get_int_size(len(word[i]), j)
		else :
			alpha.append([word[i][j], get_int_size(len(word[i]), j)])

sum = 0
start = 9
alpha.sort(key=lambda x: -1 * x[1])
for i in range(len(alpha)) :
	sum += alpha[i][1] * start
	start -= 1
print(sum)

