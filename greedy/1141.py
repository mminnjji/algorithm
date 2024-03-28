
n = int(input())
lst= []
cnt = n

for i in range(n) :
    lst.append(input())

lst.sort(key = lambda x : len(x))

for i in range(n) :
    for j in range(i+1, n) :
        if lst[i] == lst[j][:len(lst[i])] :
            cnt -= 1
            break
    
print(cnt)