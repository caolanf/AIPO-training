array_height, array_width = map(int, input().split())
array = [[0]*(array_width+1)]

for i in range(array_height):
    array.append([0]+list(map(int, input().split())))

for row in array:
    for i in range(1, len(row)):
      row[i] += row[i-1]

for r in range(1, array_height+1):
    for x in range(len(array[r])):
      array[r][x] += array[r-1][x]

x1, y1, x2, y2 = map(int, input().split())

print(array[y2][x2]+array[y1-1][x1-1] -array[y1-1][x2]-array[y2][x1-1])
