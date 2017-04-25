array = [0]+ list(map(int,input().split()))
for i in range(1, len(array)):
  array[i] += array[i-1]

ind1, ind2 = map(int, input().split())

print(array[ind2]-array[ind1-1])
