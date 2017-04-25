testcases = int(input())

for tc in range(testcases):
    len_array, n = map(int, input().split())
    array = list(map(int, input().split()))
    
    dp = [1] + [0]*n
    ans = 0
    
    while dp[:n] != [0]*n:
        if dp[n] == 1:
            ans = n
            break
        
        newdp = [0]*(n+1)
        for i in range(len(dp)):
            if dp[i] == 1:
                for element in array:
                    if i+element <= n:
                        ans = max(ans, i+element)
                        newdp[i+element] = 1
        dp = newdp[:]
    
    print(ans)
