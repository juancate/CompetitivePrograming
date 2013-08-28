from sys import stdin, stdout

n = int(stdin.readline())
numbers = [int(x) for x in stdin.readline().split()]

count = [0] * 10
zero = False

for x in numbers:
    count[x] += 1
    if x == 0:
        zero = True

if zero:
    
else:
    stdout.write("-1")
stdout.write("\n")
