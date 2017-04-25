array = list(map(int, input().split()))

dp = [1]*len(array)
for i in range(len(dp)):
    for x in range(i):
        if array[i] >= array[x]:
            dp[i] = max(dp[x]+1,dp[i])
            
print(max(dp))
