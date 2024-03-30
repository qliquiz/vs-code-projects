N, S = map(int, input().split())
array = [int(x) for x in input().split()]
top = []
count = 0

array.sort()

for i in range(len(array)):
    if sum(top) + array[i] <= S:
        top.append(array[i])
        count += 1

print(count)