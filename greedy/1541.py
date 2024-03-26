# 1581 잃어버린 괄호
"""
'-' 기호를 기준으로 앞 , 뒤로 있는 문자열들을 모두 괄호 묶어 빼줄 수 있다면 최소
- 를 기준으로 나눈 문자열을 더해 새로운 문자열에 넣어준뒤, 이를 빼준다
"""

rarr = [];
arr = input().split('-')

for i in arr :
    sum = 0
    tmp = i.split('+');
    for j in tmp :
        sum += int(j)
    rarr.append(sum)

res = rarr[0]

for i in range(1, len(rarr)):
    res -= rarr[i]
print (res)
