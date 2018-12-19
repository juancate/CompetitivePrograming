def solve(index, zero):
    if index == n:
        return 1
    if memo[index][zero] != None:
        return memo[index][zero]
    start = 1 if (zero == 1 or index == 0) else 0
    ret = 0
    for i in xrange(start, k):
        ret = ret + solve(index+1, 1 if i == 0 else 0)
    memo[index][zero] = ret
    return memo[index][zero]

n = int(raw_input())
k = int(raw_input())
memo = [[None]*2]*180

print(solve(0,0))

