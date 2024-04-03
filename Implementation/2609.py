
lst = input().split()
a = int(lst[0])
b = int(lst[1])

if a < b :
	y = a
else :
	y = b

if a < b :
	d = b
else :
	d = a

while y :
	if not a % y and not b % y :
		break
	y -= 1
print(y)

od = d
while d <= 2147483647:
	if not d % a and not d % b :
		break
	d += od

print(d)