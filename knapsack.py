def solve(i, make):
    if make < 0:
        return 0
    if make == 0:
        return 1
    if i > numcoins:
        return 0
    
    if not calculated[i][make]:
        dp[i][make] = solve(i, make-coins[i]) + solve(i+1, make)
        calculated[i][make] = True
    
    return dp[i][make]

target, numcoins = map(int, input().split())
coins = [0]+list(map(int, input().split()))
calculated = []

dp = []
for i in range(len(coins)+1):
    calculated.append([])
    dp.append([])
    for x in range(target+2):
        calculated[i].append(False)
        dp[i].append(0)

print(solve(1, target))
