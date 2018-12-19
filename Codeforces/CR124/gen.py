from random import randint, seed

limit = 100000
s = ''
for i in xrange(limit):
    s += chr(randint(97, 122))

print s
