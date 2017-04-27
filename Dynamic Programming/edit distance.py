string1 = list(input())
string2 = list(input())

dp = [list(range(len(string1)+1))]
for i in range(len(string2)):
    dp.append([i+1]+([0]*len(string1)))

for i in range(1,len(dp)):
    for x in range(1,len(dp[i])):
        if string2[i-1] == string1[x-1]:
          dp[i][x] = dp[i-1][x-1]
        else:
          dp[i][x] = min(dp[i-1][x-1], dp[i-1][x], dp[i][x-1])+1

print(dp[len(string2)][len(string1)])
